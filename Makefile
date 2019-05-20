all:
	# verify output without specific extension
	emcc --std=c++17 src/test.cpp -s WASM=1 -o build/dapp.wasm
	wasm2wat build/dapp.wasm > build/dapp.wat
