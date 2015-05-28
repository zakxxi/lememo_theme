<?php
/**
 * @file
 * Lememo API client class file.
 */

/**
 * Class lememoClient.
 */
abstract class lememoClient {
  /** @var \lememoClient singleton */
  private static $_instance;

  /**
   * Gets the current lememoClient instance or creates it if needed.
   *
   * @param string $apiEnv
   *   The API environment. Can be "dev", "staging" or "production".
   *   Defaults to "dev".
   * @param string $apiKey
   *   The API key to authorize the application.
   * @param array $options
   *   Array of options.
   * @return \lememoClient
   *   The singleton.
   */
  public static function getInstance($apiEnv = 'dev', $apiKey = '', $options = array()) {
    $className = __CLASS__ . ucfirst($apiEnv);
    if (!class_exists($className) || $className == __CLASS__) {
      $className = __CLASS__ . 'Dev';
    }
    if (empty(self::$_instance) || !(self::$_instance instanceof $className)) {
      self::$_instance = new $className($apiKey, $options);
    }
    return self::$_instance;
  }

  /** @var string */
  protected $_apiUrl;
  /** @var string */
  protected $_apiKey;

  /**
   * Class constructor.
   *
   * Only accessed via the static method \lememoClient::getInstance().
   *
   * @param string $apiKey
   *   The API key to authorize the application.
   * @param array $options
   *   Array of options.
   * @throws \lememoClientException
   */
  private function __construct($apiKey, $options = array()) {
    $this->_apiKey = $apiKey;
  }

  /**
   * Expand the endpoint URL to include given parameters.
   *
   * @param string $endPoint
   *   The endpoint URL to expand.
   * @param array $params
   *   Endpoint URL parameters.
   * @return string
   *   Expanded endpoint URL.
   */
  protected function _getEndPointUrl($endPoint = '', $params = array()) {
    return $this->_apiUrl . '/' . format_string($endPoint, $params);
  }

  /**
   * Analizes the response code to handle request errors.
   *
   * @param object $response
   *   The response returned by drupal_http_request.
   * @param string $endPoint
   *   The base endpoint URL. Used in error messages.
   * @param string $method
   *   The request method. Used in error messages.
   * @throws \lememoClientException
   */
  protected function _handleResponseCode($response, $endPoint, $method) {
    if ($response->code < 0) {
      throw new lememoClientException($response->error, $response->code);
    }
    switch ($response->code) {
      case 400:
        throw new lememoClientException(t('The request to the API is malformed.'), $response->code);
        break;
      case 401:
        throw new lememoClientException(t('The API key is unauthorized.'), $response->code);
        break;
      case 403:
        throw new lememoClientException(t('You are not allowed to use the "@endpoint" endpoint.', array('@endpoint' => $endPoint)), $response->code);
        break;
      case 404:
        throw new lememoClientException(t('The "@endpoint" endpoint does not exist.', array('@endpoint' => $endPoint)), $response->code);
        break;
      case 405:
        throw new lememoClientException(t('The "@method" method is not appropriate for the "@endpoint" endpoint.', array(
              '@endpoint' => $endPoint,
              '@method' => $method
            )), $response->code);
        break;
      case 406:
        // @TODO Checks that message conformity with the reality.
        throw new lememoClientException(t('The request sent to the "@endpoint" endpoint is incorrect.', array('@endpoint' => $endPoint)), $response->code);
        break;
      case 410:
        throw new lememoClientException(t('The "@endpoint" endpoint has been removed.', array('@endpoint' => $endPoint)), $response->code);
        break;
      case 429:
        throw new lememoClientException(t('The API server is overcharged, please try again later.'), $response->code);
        break;
      case 500:
      case 501:
      case 502:
      case 504:
      case 505:
        throw new lememoClientException(t('The API server is unreachable, please try again later.'), $response->code);
        break;
      case 503:
        throw new lememoClientException(t('The API server is off-line for maintenance, please try again later.'), $response->code);
        break;
    }
  }

  /**
   * Extracts the data from a response object.
   *
   * @param object $response
   *   The response returned by drupal_http_request.
   * @return array
   *   The data extracted from the response object.
   */
  protected function _handleResponseData($response) {
    return !empty($response->data) ? json_decode($response->data) : array();
  }

  /**
   * Send the request and basically handles the response.
   *
   * @param string $endPoint
   *   The endpoint base URL.
   * @param array $params
   *   The request parameters.
   * @return array
   *   The response data if everything was fine.
   * @throws \lememoClientException
   */
  protected function _callApi($endPoint = '', $params = array()) {
    // Define default settings.
    $defaults = array(
      'urlParams' => array(),
      'method' => 'GET',
      'data' => array(),
    );
    $settings = array_merge($defaults, $params);

    // Generate the expanded endpoint URL.
    $callUrl = $this->_getEndPointUrl($endPoint, $settings['urlParams']);

    // Prepare the request to be sent.
    $requestOpts = array(
      'method' => $settings['method'],
      'timeout' => 300,
      'headers' => array(
        'Accept' => 'application/json',
        'User-Id' => $this->_apiKey,
        'Client-IP' => variable_get('lememo_client_ip', '127.0.0.1'),
      ),
      'data' => NULL,
    );
    switch ($requestOpts['method']) {
      // If the request method is POST or PUT, data has to be encoded into the
      // options array.
      case 'POST':
      case 'PUT':
        // We use the url() function to ease the data encoding.
        $requestOpts['data'] = substr(url('', array(
              'external' => TRUE,
              'query' => $settings['data']
            )), 1);
        break;

      // In all the other cases, data has to be put in the URL.
      default:
        $callUrl = url($callUrl, array(
            'external' => TRUE,
            'query' => $settings['data']
          ));
        break;
    }

    // Send the request.
    $response = drupal_http_request($callUrl, $requestOpts);

    // React to all possible error codes.
    $this->_handleResponseCode($response, $endPoint, $requestOpts['method']);

    // Decode and return the response.
    return $this->_handleResponseData($response);
  }

  /**
   * Checks if the API URL is reachable and properly configured.
   *
   * Checks the API server response, the API version and the API key validity.
   *
   * @return bool
   *   TRUE if the API URL is properly configured.
   * @throws \lememoClientException
   */
  public function checkApi() {
    return (bool) $this->_callApi();
  }


  // ---------------------------------------------------------------------------
  // Endpoints.

  /**
   * Gets updated businesscard between two date.
   *
   * @param int $timeElapsedFrom
   * @param int $timeElapsedTo
   * @return array
   */
  public function getUpdated($timeElapsedFrom, $timeElapsedTo) {
    $options = array(
      'urlParams' => array(
        '@timeElapsedFrom' => $timeElapsedFrom,
        '@timeElapsedTo' => $timeElapsedTo,
      ),
    );

    return $this->_callApi('updated/@timeElapsedFrom-@timeElapsedTo', $options);
  }

  /**
   * Gets removed businesscard between two date.
   *
   * @param int $timeElapsedFrom
   * @param int $timeElapsedTo
   * @return array
   */
  public function getRemoved($timeElapsedFrom, $timeElapsedTo) {
    $options = array(
      'urlParams' => array(
        '@timeElapsedFrom' => $timeElapsedFrom,
        '@timeElapsedTo' => $timeElapsedTo,
      ),
    );

    return $this->_callApi('removed/@timeElapsedFrom-@timeElapsedTo', $options);
  }


  /**
   * Gets one businesscard by id.
   *
   * @param int $id
   * @return array
   */
  public function getbusinesscard($id) {
    $options = array(
      'urlParams' => array(
        '@id' => $id,
      ),
    );

    return $this->_callApi('updated/@id', $options);
  }
}

/**
 * Class lememoClientDev.
 */
class lememoClientDev extends lememoClient {
  protected $_apiUrl = 'http://api.lememo.net/json/businesscard';
}

/**
 * Class lememoClientStaging.
 */
class lememoClientStaging extends lememoClient {
  protected $_apiUrl = 'http://api.lememo.net/json/businesscard';
}

/**
 * Class lememoClientProduction.
 */
class lememoClientProduction extends lememoClient {
  protected $_apiUrl = 'http://api.lememo.net/json/businesscard';
}

/**
 * Class lememoClientException.
 */
class lememoClientException extends Exception {}