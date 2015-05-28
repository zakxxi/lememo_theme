<?php


/**
 * Class lememoBusinesscardMigration
 */
abstract class lememoBusinesscardMigration extends Migration {

  /**
   * List of image fields that need specific treatment during the migration.
   * @var array
   */
  private $image_fields = array('field_cover', 'field_logo', 'field_pictures');
  /**
   * @param array $arguments
   */
  public function __construct($arguments) {
    parent::__construct($arguments);
    $columns = [
      array('id', t('api id')),
      array('company', t('Company')),
      array('title', t('Title')),
      array('siret', t('Siret')),
      array('tva', t('TVA')),
      array('uri', t('uri')),
      array('description.short', t('Short descriptions')),
      array('description.long', t('Long descriptions')),
      array('address', t('Address')),
      array('resources.cover', t('Ressource cover')),
      array('resources.logo', t('Ressource logo')),
      array('resources.pictures', t('Ressource logo')),
      array('address.city.latitude', t('Latitude')),
      array('address.city.longitude', t('Longitude')),
      array('address.country.name', t('Country')),
      array('address.district.name', t('District')),
      array('address.county.name', t('County')),
      array('address.city.name', t('City')),
      array('phone1', t('Phone number 1')),
      array('phone2', t('Phone number 2')),
      array('website', t('Website Url')),
    ];
//    $path = drupal_realpath(DRUPAL_ROOT . DIRECTORY_SEPARATOR . '..' . DIRECTORY_SEPARATOR . 'ressources' . DIRECTORY_SEPARATOR . 'import');
    $path = drupal_realpath(DRUPAL_ROOT . DIRECTORY_SEPARATOR . 'ressources' . DIRECTORY_SEPARATOR . 'import');
    $this->source = new MigrateSourceJSON($path . DIRECTORY_SEPARATOR . $arguments['reference_file'], 'id', $columns);
    $this->destination = new MigrateDestinationNode('fiche');
    $this->map = new MigrateSQLMap($this->machineName,
      array('id' =>
        array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
         )
      ),
      MigrateDestinationNode::getKeySchema()
    );
    // Mapped fields
    $this->addSimpleMappings(array('status', 'uid'));
    $this->addFieldMapping('field_id_api', 'id');
    $this->addFieldMapping('title', 'company');
    $this->addFieldMapping('field_company', 'company');
    $this->addFieldMapping('field_companycleaned', 'companyCleaned');
    $this->addFieldMapping('field_siret', 'siret');
    $this->addFieldMapping('field_tva', 'tva');
    $this->addFieldMapping('field_mail', 'mail');
    $this->addFieldMapping('field_description_short', 'description.short');
    $this->addFieldMapping('field_description_long', 'description.long');

    $this->addFieldMapping('field_cover', 'resources.cover')->callbacks(array($this, 'switchDomain'));
    $this->addFieldMapping('field_cover:file_class')->defaultValue('lememoMigrateFileUriAsIs');
    $this->addFieldMapping('field_cover:file_replace')->defaultValue(MigrateFile::FILE_EXISTS_REUSE);

    $this->addFieldMapping('field_logo', 'resources.logo')->callbacks(array($this, 'switchDomain'));
    $this->addFieldMapping('field_logo:file_class')->defaultValue('lememoMigrateFileUriAsIs');
    $this->addFieldMapping('field_logo:file_replace')->defaultValue(MigrateFile::FILE_EXISTS_REUSE);

    $this->addFieldMapping('field_pictures', 'resources.pictures')->callbacks(array($this, 'switchDomain'));
    $this->addFieldMapping('field_pictures:file_class')->defaultValue('lememoMigrateFileUriAsIs');
    $this->addFieldMapping('field_pictures:file_replace')->defaultValue(MigrateFile::FILE_EXISTS_REUSE);

    $this->addFieldMapping('field_position')->defaultValue('point');
    $this->addFieldMapping('field_position:input_format')->defaultValue('lat/lon');
    $this->addFieldMapping('field_position:geo_type')->defaultValue('point');
    $this->addFieldMapping('field_position:lat', 'address.city.latitude')->callbacks(array($this, 'convertDecimal'));
    $this->addFieldMapping('field_position:lon', 'address.city.longitude')->callbacks(array($this, 'convertDecimal'));

    $this->addFieldMapping('field_country', 'address.country.name');
    $this->addFieldMapping('field_district', 'address.district.name');
    $this->addFieldMapping('field_county', 'address.county.name');
    $this->addFieldMapping('field_city', 'address.city.name');
    $this->addFieldMapping('field_rows', 'address.rows');
    $this->addFieldMapping('path', 'uri');
  }

  /**
   * Set default value to the row.
   *
   * @param $row
   */
  public function prepareRow($row) {
    parent::prepareRow($row);
    $this->flatten($row);
    $row->status = 1;
    $row->uid = 1;
    // Disable pathauto, just in case.
    $row->path['pathauto'] = 0;
  }

  /**
   * Add fake data to the node before saving it.
   *
   * @param $node
   * @param \stdClass $row
   */
  public function prepare($node, stdClass $row) {
    // Add fake width and height to image field to avoid distance fetching that
    // cost a lot of time.
    foreach($this->image_fields as $name) {
      if (!empty($node->$name)) {
        $this->fake_dimension($node->$name);
      }
    }
  }

  /**
   * Set Fake value to the image dimensions to avoid distance fetching of the
   * data that will make the migration very slow.
   *
   * @param $items
   */
  private function fake_dimension(&$items) {
    foreach ($items['und'] as $key => $item) {
      $items['und'][$key]['width'] = 0;
      $items['und'][$key]['height'] = 0;
    }
  }

  /**
   * Flatten the data array so it's easier to create migration mapping.
   *
   * @param $obj
   * @param string $prefix
   * @param null $subset
   */
  public function flatten($obj, $prefix = '', $subset = NULL) {
    if (NULL === $subset) {
      $subset = $obj;
    }
    foreach ($subset as $key => $value) {
      $new_key = $prefix . $key;
      if (is_object($value)) {
        $this->flatten($obj, $new_key . '.', $value);
      }
      else {
        $obj->$new_key = $value;
      }
    }
  }

  /**
   * Switch image domain to have access to some images.
   *
   * @param $value
   * @return mixed
   */
  public function switchDomain($value) {
    $new_value = str_replace('static.lememo.dev', 'static.lememo.com', $value);
    return $new_value;
  }

  /**
   * Replace comma by dot, used by the geofield data so longitude and latitude
   * are real decimal value for Drupal.
   *
   * @param $value
   * @return mixed
   */
  public function convertDecimal($value) {
    $new_value = str_replace(',', '.', $value);
    return $new_value;
  }
}

/**
 * Initial import for Businesscard
 */
class lememoBusinesscardInitialMigration extends lememoBusinesscardMigration {
}

/**
 * Nightly import for Businesscard
 */
class lememoBusinesscardNightlyMigration extends lememoBusinesscardMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->addFieldMapping('nid', 'id')
      ->sourceMigration('lememo_businesscard_inital');
  }
}

/**
 * Specific version of MigrateFileUriAsIs that use an rewrited version of the
 * file_save function that didn't fetch the size of the file.
 */
class lememoMigrateFileUriAsIs extends MigrateFileBase {
  /**
   * @param $value
   * @param $owner
   * @return \stdClass
   */
  public function processFile($value, $owner) {
    $file = $this->lememo_file_save($this->createFileEntity($value, $owner));
    return $file;
  }


  /**
   * Saves a file object to the database. This is an overidden version of the
   * drupal file_save method that remove cost call of filesize when the image
   * is remote.
   *
   * If the $file->fid is not set a new record will be added.
   *
   * @param $file
   *   A file object returned by file_load().
   *
   * @return $file
   *   The updated file object.
   *
   * @see hook_file_insert()
   * @see hook_file_update()
   */
  private function lememo_file_save(stdClass $file) {
    $file->timestamp = REQUEST_TIME;
    //$file->filesize = filesize($file->uri);
    $file->filesize = 0;

    // Load the stored entity, if any.
    if (!empty($file->fid) && !isset($file->original)) {
      $file->original = entity_load_unchanged('file', $file->fid);
    }

    // @TODO check what is missing when remove this hooks calls
    //module_invoke_all('file_presave', $file);
    //module_invoke_all('entity_presave', $file, 'file');

    if (empty($file->fid)) {
      drupal_write_record('file_managed', $file);
      // @TODO check what is missing when remove this hooks calls
      // Inform modules about the newly added file.
      //module_invoke_all('file_insert', $file);
      //module_invoke_all('entity_insert', $file, 'file');
    }
    else {
      drupal_write_record('file_managed', $file, 'fid');
      // @TODO check what is missing when remove this hooks calls
      // Inform modules that the file has been updated.
      //module_invoke_all('file_update', $file);
      //module_invoke_all('entity_update', $file, 'file');
    }

    // Clear internal properties.
    unset($file->original);
    // @TODO Need to check if an clear_cache at the end of the migration is ok.
    // Clear the static loading cache.
    //entity_get_controller('file')->resetCache(array($file->fid));
    return $file;
  }
}