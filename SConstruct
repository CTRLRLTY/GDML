from glob import glob

bits = 64
godot_headers_path = "godot-cpp/godot-headers/"
cpp_bindings_path = "godot-cpp/"
cpp_library = "libgodot-cpp.linux.debug." + str(bits)

options = {
    "CXX": "clang++",
    "CCFLAGS": "-arch x86_64 -fPIC -std=c++20 -g -O0",
    "CPPPATH": ['.', './include/', godot_headers_path, cpp_bindings_path + 'include/', cpp_bindings_path + 'include/core/', cpp_bindings_path + 'include/gen/'],
    "LIBPATH": [cpp_bindings_path + 'bin/'],
    "LIBS": [cpp_library],
    "COMPILATIONDB_USE_ABSPATH": True
}

env = Environment(**options)
env.Tool('compilation_db')
env.CompilationDatabase()
sources = glob('./src/*.cpp')

env.SharedLibrary(target="dist/gdml", source=sources)
