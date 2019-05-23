#!/bin/bash
echo "Counting drops: $(cat build/examples/HelloWorld.wat | grep -c -E 'drop')"
