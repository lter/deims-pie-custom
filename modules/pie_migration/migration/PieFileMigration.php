<?php

/**
 * @file
 * Definition of PieFileMigration.
 */

class PieFileMigration extends DeimsFileMigration {

  public function prepare($file, $row) {

    $file->value = 'public://' . str_replace("sites/pie-lter.ecosystems.mbl.edu/files/","",$file->value);
    // Hack to make migration work as we expect.
    if (!file_exists($file->value)) {
      throw new MigrateException("The file at {$file->value} does not exist.");
    }


  }

}
