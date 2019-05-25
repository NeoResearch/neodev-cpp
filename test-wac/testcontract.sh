#!/bin/bash

#make examples_c/NeoContract.wasm
emcc -O2 -Wall -Werror -MMD -MP -DPLATFORM=1 -s WASM=1 -s SIDE_MODULE=1 -s LEGALIZE_JS_FFI=0 -I examples_c/include -s USE_SDL=2 examples_c/NeoContract1.cpp -o examples_c/NeoContract1.wasm
#em++ -g -O2 --std=c++17 -Wall -Werror -MMD -MP -DPLATFORM=1 -s WASM=1 -s SIDE_MODULE=1 -s LEGALIZE_JS_FFI=0 -I examples_c/include -s USE_SDL=2 examples_c/NeoContract1.cpp -o examples_c/NeoContract1.wasm

./wabt/bin/wat-desugar examples_c/NeoContract1.wast > examples_c/NeoContract1.wat
cat examples_c/NeoContract1.wat

