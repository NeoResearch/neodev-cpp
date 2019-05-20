# neo-cpp-devpack
C++ devpack for Neo blockchain


## dependencies

To compile, you will need emscripten `emcc`, since the process uses using WebAssembly Neo Compiler (see `wasm2neo` project).

### Building EMSDK

```
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest
# Make the "latest" SDK "active" for the current user. (writes ~/.emscripten file)
./emsdk activate latest
# Activate PATH and other environment variables in the current terminal
source ./emsdk_env.sh
```

### Building WABT (WebAssembly Toolkit)

```
git clone git@github.com:WebAssembly/wabt.git
cd wabt
mkdir build
cd build
cmake ..
cmake --build .
```

## License

MIT 2019
