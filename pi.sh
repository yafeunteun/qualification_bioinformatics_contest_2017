#!/usr/bin/env bash

make clean

easea $1

N_THREADS=$((`nproc` * 2))
echo "Using $N_THREADS threads for compilation"

sed -i 's/globalRandomGenerator->random_shuffle/random_shuffle/g' rosalindIndividual.cpp
make -j $N_THREADS
