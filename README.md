# deims-pie-custom
Migration and customization for the Plum Island Ecosystems LTER

### Pre-reqs.
* Install DEIMS
* Have a connector to your PIE DEIMS database on your settings.local (see DEIMS documentation)

###Clone

git clone --branch 7.x-1.x git@github.com:lter/deims-pie-custom.git

into a place of your choice (current directory, Desktop, etc)

###Or download this module from:

https://github.com/lter/deims-pie-custom/archive/7.x-1.x.zip

### Install
Extract the contents in a local directory, you will copy the parts inside to different places in your DEIMS install, as we explain now. Once you have the repository locally, create a folder named modules under your DEIMS root sites/default (unless you have already made it)

Under the sites/default/modules, place the migration related modules there.

The features may override existing DEIMS features or may be new features. If these are overrides, do exactly that, copy over the existing folder.  Otherwise just enable the new features, preferably before the migration.

### Migration

Run the migrations from independent to dependent.  I.e; first users and taxonomies, then content types, from simple to complex.  Usually the data-set content type nodes will come last, the organization first.

Notes on geo-migration: Ensure the field handler for geofield is disabled in the migrate->config page. also, the geofield widget will dictate which is the master col, so if your widget is BB, a 'lat/lon', will result in a POLYGON albeit miniscule, with a dot. This may be to your advantage (glacier stakes?) or detriment. Ensure you know what you want before migration.

### Features 

Customizations to fields, views, content types and layouts for PIE are captured in the features folder, and managed by the Drupal Contrib module named "Features"

### Other supporting notes 

Assets, plans, and other supporting notes are in google docs, may post some of those here.
