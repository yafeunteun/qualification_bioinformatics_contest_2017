#!/usr/bin/env bash

make clean

easea $1

sed -i 's/globalRandomGenerator->random_shuffle/random_shuffle/g' rosalindIndividual.cpp
make -j 128
