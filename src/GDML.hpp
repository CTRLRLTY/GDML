#ifndef GDML_H
#define GDML_H

#include <Godot.hpp>
#include <Node.hpp>
#include <GML.hpp>
#include "GTree.hpp"

namespace godot {
  class GDML : public Node {
    GODOT_CLASS(GDML, Node)

    private:
      friend class GTree;

      static Dictionary class_count_to_dict(GML::CLASS_COUNT class_count);
      static GML::DATA<Variant> create_data(Array data);
      static GML::TDATA<Variant> create_tdata(Dictionary tdata);
      static GML::TDATA_COL<Variant> create_tdatacol(Array tdatacol);

    public:
      static void _register_methods();

      GDML();
      ~GDML();
      void _ready();
      void _init();
      GTree* create_tree(Array training_data);
  };
}

#endif // GDML_H
