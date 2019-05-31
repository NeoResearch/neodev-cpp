#!/bin/bash

set -euxo pipefail # safer script: will fail

wget https://github.com/google/googletest/archive/release-1.8.1.tar.gz
rm -rf gtestlib
mkdir gtestlib
tar xf release-1.8.1.tar.gz -C gtestlib --strip-components=1
cd gtestlib
#cmake -DBUILD_SHARED_LIBS=ON .
cmake .
make
