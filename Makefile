all:
	# verify output without specific extension
	#emcc --std=c++17 src/test.cpp -s WASM=1 -o build/dapp.wasm
	#-s SIDE_MODULE=1 -Oz -s ONLY_MY_CODE=1
	#em++ --std=c++17 src/test.cpp -s WASM=1 -s SIDE_MODULE=1 -Oz -s ONLY_MY_CODE=1 -o build/dapp.wasm
	em++ --std=c++17 src/test.cpp -s WASM=1 -s SIDE_MODULE=1 -s "EXPORTED_FUNCTIONS=['NeoMain']" -O3 -s ONLY_MY_CODE=1 -o build/dapp.wasm

	wasm2wat build/dapp.wasm > build/dapp.wat
