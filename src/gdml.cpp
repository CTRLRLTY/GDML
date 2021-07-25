#include "gdml.h"

using namespace godot;

void GDML::_register_methods() {
  register_method("test", &GDML::test);
  register_method("_ready", &GDML::_ready);
}

GDML::GDML() {}
GDML::~GDML() {}

void GDML::_init() {}
void GDML::_ready() {
  test();
  Godot::print("Please Work!!!!!!");
}

void GDML::test() {
  Godot::print("Hello World!");
}
