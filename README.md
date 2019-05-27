# neo-cpp-devpack
C++ devpack for Neo blockchain


## online editors

Code can be compiled using online WebAssembly editors.
Suggestion: `https://mbebenita.github.io/WasmExplorer/` (Select C++1z or C++17)

## Hello World example

### class based 

![](./Example-ClassHelloWorld.png)

### global-function based 

![](./Example-HelloWorld.png)


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
