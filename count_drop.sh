#!/bin/bash
echo "Counting drops: $(cat build/examples/$1.wast | grep -c -E 'drop')"
