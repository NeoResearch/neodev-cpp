install wac and follow instructions to install wabt: https://github.com/kanaka/wac

looks nice and updated, but wat/wast is too ugly for parsing now...
too many global write/read

my tests were performed using docker (around 1.7GB for whole compiler, but only gcc 32-bits):

cd wac
docker run -v `pwd`:/wac -w /wac -it kanaka/wac bash


