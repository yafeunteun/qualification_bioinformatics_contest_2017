#!/bin/bash


nb_reads=`cat $1 | head -n 2 | tail -n 1`

##echo $nb_reads

sed -i  "s/#define N_READS .*/#define N_READS $nb_reads/"  ./rosalind.ez

sh pi.sh rosalind.ez

./rosalind $1
