from glob import glob

# Archtecture Targets
bits = 64

# Libraries Paths
GML_path = "GML/bin/"
godotcpp_path = "godot-cpp/"
godotheaders_path = "godot-cpp/godot-headers/"

libgodotcpp = "libgodot-cpp.linux.debug." + str(bits)

options = {
    "CXX": "clang++",
    "CCFLAGS": "-arch x86_64 -fPIC -std=c++20 -g -O0",
    "CPPPATH": ['.', './GML/headers/', godotheaders_path, godotcpp_path + 'include/', godotcpp_path + 'include/core/', godotcpp_path + 'include/gen/'],
    "LIBPATH": [godotcpp_path + 'bin/', GML_path],
    "LIBS": [libgodotcpp],
    "COMPILATIONDB_USE_ABSPATH": True
}

env = Environment(**options)
env.Tool('compilation_db')
env.CompilationDatabase()
sources = glob('./src/*.cpp')

env.SharedLibrary(target="dist/gdml", source=sources)
