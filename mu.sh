#!/bin/bash


nb_reads=`cat $1 | head -n 2 | tail -n 1`
dna_size=`cat ~/tests/1  | head -n 1 | wc -c`
##echo $nb_reads

sed -i  "s/#define N_READS .*/#define N_READS $nb_reads/"  ./rosalind.ez
sed -i "s/#define DNA_SIZE .*/#define DNA_SIZE $dna_size/" ./rosalind.ez
sh pi.sh rosalind.ez

./rosalind $1
