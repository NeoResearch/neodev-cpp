CLANG_BIN=/home/imcoelho/git-reps/make-llvm/build/bin
BINARYEN_BIN=/home/imcoelho/git-reps/binaryen/build/bin
WABT_BIN=/home/imcoelho/git-reps/wabt/build
WABT_BIN_NEW=/home/imcoelho/git-reps/wabt/bin

all:
	# verify output without specific extension
	#emcc --std=c++17 src/test.cpp -s WASM=1 -o build/dapp.wasm
	#-s SIDE_MODULE=1 -Oz -s ONLY_MY_CODE=1
	#em++ --std=c++17 src/test.cpp -s WASM=1 -s SIDE_MODULE=1 -Oz -s ONLY_MY_CODE=1 -o build/dapp.wasm
	#em++ --std=c++17 src/test.cpp -s WASM=1 -s SIDE_MODULE=1 -s "EXPORTED_FUNCTIONS=['NeoMain']" -O3 -s ONLY_MY_CODE=1 -o build/dapp.wasm

	$(CLANG_BIN)/clang++ --std=c++1z -emit-llvm --target=wasm32 -Oz src/test.cpp -c -o build/dapp.bc
	$(CLANG_BIN)/llc -asm-verbose=false -o build/dapp.s build/dapp.bc
	#$(CLANG_BIN)/clang++ --std=c++1z -emit-llvm --target=wasm32 -Wl,--no-threads -Oz src/TestSimple.cpp --compile -o build/dapp.wasm
	$(BINARYEN_BIN)/s2wasm build/dapp.s > build/dapp.wast
	$(WABT_BIN)/wast2wasm build/dapp.wast > build/dapp.wasm
	$(WABT_BIN_NEW)/wat2wasm build/dapp.wast > build/dapp2.wasm
	$(WABT_BIN_NEW)/wasm2wat build/dapp2.wasm > build/dapp2.wat



#binaryen
#b16768ec9b72d075ae2e36cc85aa216fdf4fd354

#wabt
#8e1f6031e9889ba770c7be4a9b084da5f14456a0
