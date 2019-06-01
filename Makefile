CLANG_BIN=./clang-llvm/build/bin
BINARYEN_BIN=./binaryen/build/bin
WABT_BIN=./wabt/build
WABT_BIN_NEW=./wabt-new/bin

all: examples #spectests
	cp build/examples/HelloWorld.wast wat2json/input.wast
	(cd wat2json && make && make run)

srctest:
	# verify output without specific extension
	#emcc --std=c++17 src/test.cpp -s WASM=1 -o build/dapp.wasm
	#-s SIDE_MODULE=1 -Oz -s ONLY_MY_CODE=1
	#em++ --std=c++17 src/test.cpp -s WASM=1 -s SIDE_MODULE=1 -Oz -s ONLY_MY_CODE=1 -o build/dapp.wasm
	#em++ --std=c++17 src/test.cpp -s WASM=1 -s SIDE_MODULE=1 -s "EXPORTED_FUNCTIONS=['NeoMain']" -O3 -s ONLY_MY_CODE=1 -o build/dapp.wasm

	$(CLANG_BIN)/clang++ -I/usr/include/c++/4.9 -I/usr/include/x86_64-linux-gnu/c++/7 --std=c++1z -emit-llvm --target=wasm32 -Oz src/test.cpp -c -o build/dapp.bc
	$(CLANG_BIN)/llc -asm-verbose=false -o build/dapp.s build/dapp.bc
	#$(CLANG_BIN)/clang++ --std=c++1z -emit-llvm --target=wasm32 -Wl,--no-threads -Oz src/TestSimple.cpp --compile -o build/dapp.wasm
	$(BINARYEN_BIN)/s2wasm build/dapp.s > build/dapp.wast
	$(WABT_BIN)/wast2wasm build/dapp.wast > build/dapp.wasm
	$(WABT_BIN)/wast-desugar --generate-names build/dapp.wast > build/dapp.wat
	@echo "Number of Loads should be Zero. Checking!"
	@test `cat build/dapp.wat | grep -c -E 'i32.load|i64.load|i32.store|i64.store|global'` -eq 0
	@echo "Check passed!"
	@echo "Number of lines:" `wc -l build/dapp.wat`
	#$(WABT_BIN_NEW)/wat2wasm build/dapp.wast > build/dapp2.wasm
	#$(WABT_BIN_NEW)/wasm2wat build/dapp2.wasm > build/dapp2.wat

examples: HelloWorld HelloWorldTests HelloWorld_em Minimal_emc
	@echo Building examples!

# examples
%: examples/%.cpp
	@echo 
	@echo "Building example with clang + binaryen $<"
	$(CLANG_BIN)/clang++ --std=c++1z -Isrc/ -emit-llvm --target=wasm32 -O1 $< -c -o build/examples/$@.bc
	$(CLANG_BIN)/llc -asm-verbose=false -o build/examples/$@.s build/examples/$@.bc
	$(BINARYEN_BIN)/s2wasm build/examples/$@.s > build/examples/$@.wast   # not real wast, perhaps?
	$(WABT_BIN)/wast2wasm build/examples/$@.wast -o build/examples/$@.wasm
	$(WABT_BIN)/wast-desugar --generate-names build/examples/$@.wast > build/examples/$@.desugar.wast #wast or wat ?
	# cannot test for zero loads, as they seem necessary for object "this" pointers
	#@echo "Number of Loads should be Zero. Checking!"	
	#@test `cat build/examples/$@.desugar.wast | grep -c -E 'i32.load|i64.load|i32.store|i64.store|global'` -eq 0
	#@echo "Check passed!"
	@./count_drop.sh $@
	@echo "Number of lines on s-expression file:" `wc -l build/examples/$@.desugar.wast`
	@echo "Converting wast to json spec test (env should be zero!)"
	@$(WABT_BIN_NEW)/wast2json build/examples/$@.wast -o build/examples/$@.wast.json
	@./count_env.sh $@
	@echo 

#example with emscripten
%_em: examples/%.cpp
	@echo 
	@echo "Building example with emscripten $<"
	em++ -Isrc -std=c++17 -g $< -s WASM=1 -s SIDE_MODULE=1 -s ONLY_MY_CODE=1 -o build/examples/$@.wasm
	#em++ -Isrc -std=c++17 -g $< -s WASM=1 -s EXPORTED_FUNCTIONS="[_Z4Mainv]" -o build/examples/$@.wasm
	$(WABT_BIN_NEW)/wasm2wat build/examples/$@.wasm > build/examples/$@.wat
	$(WABT_BIN_NEW)/wat-desugar build/examples/$@.wat > build/examples/$@.desugar.wat
	@echo "Converting wast to json spec test (env should be zero!)"
	@$(WABT_BIN_NEW)/wast2json build/examples/$@.wast -o build/examples/$@.wast.json
	@./count_env.sh $@
	@echo "Number of lines on s-expression file:" `wc -l build/examples/$@.desugar.wat`
	@echo 

#example with emscripten
%_emc: examples/%.c
	@echo 
	@echo "Building C example with emscripten $<"
	emcc -Isrc -std=c89 -g $< -s WASM=1 -s ONLY_MY_CODE=1 -o build/examples/$@.wasm
	#em++ -Isrc -std=c++17 -g $< -s WASM=1 -s EXPORTED_FUNCTIONS="[_Z4Mainv]" -o build/examples/$@.wasm
	$(WABT_BIN_NEW)/wasm2wat --generate-names build/examples/$@.wasm > build/examples/$@.wat
	$(WABT_BIN_NEW)/wat-desugar build/examples/$@.wat > build/examples/$@.desugar.wat
	@echo "Converting wast to json spec test (env should be zero!)"
	@$(WABT_BIN_NEW)/wast2json build/examples/$@.wast -o build/examples/$@.wast.json
	@./count_env.sh $@
	@echo "Number of lines on s-expression file:" `wc -l build/examples/$@.desugar.wat`
	@echo 

spectests: build/examples/Minimal_emc.wast.json
	@echo
	@echo " ============ Will run spec tests =============="
	#@echo "MINIMAL (clang)"
	#$(WABT_BIN_NEW)/spectest-interp build/examples/Minimal.wast.json
	#@echo
	@echo "MINIMAL (emsdk)"
	$(WABT_BIN_NEW)/spectest-interp build/examples/Minimal_emc.wast.json
	@echo


vendor:
	@echo "Install docs"
	sudo npm -g install apidoc
	@echo "Should install llvm with clang. Also binaryen and wabt"
	@echo TODO! See correct/compatible versions below on comments.


#binaryen
#b16768ec9b72d075ae2e36cc85aa216fdf4fd354

#wabt
#8e1f6031e9889ba770c7be4a9b084da5f14456a0

#llvm + clang
#(cd clang && git checkout e4de58127fa1d8d22ee8043cef9b4d8a807b6cde)
#(cd llvm && git checkout 08b86793476e08fc0937e70058e2a94808c988e7)
#(mkdir build && cd build && cmake -DLLVM_ENABLE_PROJECTS=clang -G "Unix Makefiles" -DLLVM_TARGETS_TO_BUILD= -DLLVM_EXPERIMENTAL_TARGETS_TO_BUILD=WebAssembly ../llvm)



doc:
	apidoc -i src/ -f ".*\\.hpp$$" -o docs/
