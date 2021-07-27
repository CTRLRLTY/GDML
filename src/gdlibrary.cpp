#include "GDML.hpp"

extern "C" {
  void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options *options) {
    godot::Godot::gdnative_init(options);
  }

  void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options *options) {
    godot::Godot::gdnative_terminate(options);
  }

  void GDN_EXPORT godot_nativescript_init(void *handle) {
    godot::Godot::nativescript_init(handle);
    godot::register_class<godot::GDML>();
    godot::register_class<godot::GTree>();
  }
};
