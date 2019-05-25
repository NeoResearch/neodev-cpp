#!/bin/bash
echo "Counting env: $(cat build/examples/$1.wast | grep -c -E 'env')"
