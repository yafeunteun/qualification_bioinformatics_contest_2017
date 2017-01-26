#!/usr/bin/env bash

make clean

easea $1

if [[ `uname` == 'Darwin' ]]; then
  cp Makefile.macos Makefile
fi

if [[ `uname` == 'Darwin' ]]; then
  N_THREADS=$((`sysctl -n hw.ncpu` * 2))
else
  N_THREADS=$((`nproc` * 2))
fi

echo "Using $N_THREADS threads for compilation"

sed -i.bak 's/globalRandomGenerator->random_shuffle/random_shuffle/g' rosalindIndividual.cpp
make -j $N_THREADS
