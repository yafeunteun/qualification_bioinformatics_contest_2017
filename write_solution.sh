
#!/bin/bash


best=`tail -n 1 rosalind.pop`
echo $best > result.mordor
cat $1 | tail -n $((`cat $1 | wc -l`-2)) >> result.mordor
`whereis python  | cut -d " " -f 2`   write_solution.py > submit.txt
