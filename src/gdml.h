#ifndef GDML_H
#define GDML_H

#include <Godot.hpp>
#include <Node.hpp>


namespace godot {
  class GDML : public Node {
    GODOT_CLASS(GDML, Node)
  
  private:
  public:
    static void _register_methods();
    GDML();
    ~GDML();
    void test();
    void _ready();
    void _init();
  };
}

#endif // GDML_H
