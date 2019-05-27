# wat2json

WAT to JSON converts a s-expression textual wasm (.wat) into a .json format.
It accepts "non-desugarized" versions of .wat (or .wast) starting with line `(module` and ending with line `)`.

## How to use

`make`

`./wat2json file.wat` or `./wat2json file.wast`


## License
License is currently LGPLv3, due to Scanner++ library, but can change in the future, when removing this dependency.
