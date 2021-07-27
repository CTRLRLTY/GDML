#include "GTree.hpp"
#include "GDML.hpp"

using namespace godot;

GTree::GTree() {}
GTree::~GTree() {}

void GTree::_register_methods() {
  register_method("predict", &GTree::predict);
  register_method("test", &GTree::test);
}

void GTree::_init() {
  treename = "DefaultTree";
}

Dictionary GTree::predict(Array data) {
  Godot::print("Predicting stuff!!");
  Godot::print(Variant(_tree.empty()));
  GML::DECISION_NODE dnode = _tree.predict(GDML::create_data(data));
  GML::NODE_DATA nodedata = dnode.nodedata();
  GML::CLASS_COUNT counts = *nodedata.count_sptr;

  return GDML::class_count_to_dict(counts);
}

void GTree::set_tree(GML::TREE<Variant>& tree) {
  this->_tree = tree;
}

void GTree::test() {
  Godot::print(this->treename);
}
