#ifndef SCRIPTED_TREE_H
#define SCRIPTED_TREE_H
#include <Godot.hpp>
#include <Resource.hpp>
#include <GML.hpp>
#include <Variant.hpp>

namespace godot {
  class GTree : public Resource {
    GODOT_CLASS(GTree, Resource); 

    private:
      friend class GDML;

      GML::TREE<Variant> _tree;
      void set_tree(GML::TREE<Variant>& tree);
      Dictionary predict(Array data);

    public:
      static void _register_methods();
      void _init();
      GTree();
      ~GTree();
  };
  
}
#endif
