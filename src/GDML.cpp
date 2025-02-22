#include <Dictionary.hpp>
#include "GDML.hpp"
#include "GML.hpp"
#include <String.hpp>

using namespace godot;

void GDML::_register_methods() {
  register_method("_ready", &GDML::_ready);
  register_method("create_tree", &GDML::create_tree);
}

GDML::GDML() {}
GDML::~GDML() {}

void GDML::_init() {}
void GDML::_ready() {}

Dictionary GDML::class_count_to_dict(GML::CLASS_COUNT class_count) {
  Dictionary dict;
  for(const auto& [key, val] : class_count) {
    std::string k = key;
    dict[k.c_str()] = Variant(val);
  }

  return dict;
}

GML::DATA<Variant> GDML::create_data(Array data) {
  GML::DATA<Variant> gml_data;
  int data_size = data.size(); 
  for(int i = 0; i < data_size; ++i) {
    gml_data.push_back(data[i]);
  }

  return gml_data;
}

GML::TDATA<Variant> GDML::create_tdata(Dictionary tdata) {
  GML::TDATA<Variant> gml_tdata;
  String label = tdata["label"];
  Array rows = tdata["rows"];
  int row_size = rows.size();
  Variant vd[row_size];

  gml_tdata.label = label.utf8().get_data();

  for(int i = 0; i < row_size; ++i) {
    gml_tdata.push_back(rows[i]);
  }
  
  return gml_tdata;
}

GML::TDATA_COL<Variant> GDML::create_tdatacol(Array tdatacol) {
  GML::TDATA_COL<Variant> gml_tdatacol;
  int tdata_size = tdatacol.size();

  for(int i = 0; i < tdata_size; ++i) {
    gml_tdatacol.push_back(create_tdata(tdatacol[i]));
  }

  return gml_tdatacol;
}

GTree* GDML::create_tree(Array training_data) {
  Godot::print("Creating Tree!");
  auto gtree = GTree::_new();

  GML::TDATA_COL tdata_col = create_tdatacol(training_data);
  GML::TREE<Variant> tree(tdata_col);

  gtree->set_tree(tree);

  return gtree;
}
