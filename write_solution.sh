
#!/bin/bash

best=`tail -n 1 rosalind.pop`
nb_elems=`echo $best | wc -w`

read_usage=`echo $best | cut -d " " -f 1-$((($nb_elems-1)/2))`
genome=`echo $best | cut -d " " -f $(((($nb_elems-1)/2)+1))-$((nb_elems-1))`
fitness_score=`echo $best | cut -d " " -f $nb_elems`
echo $fitness_score > result.mordor
echo $genome >> result.mordor
echo $read_usage >> result.mordor

cat $1 | tail -n $((`cat $1 | wc -l`-2)) >> result.mordor

`whereis python  | cut -d " " -f 2`   write_solution.py > submit.txt
