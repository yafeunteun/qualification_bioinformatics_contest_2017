
f = open('result.mordor')
fitness_score = f.readline()
genome = [int(x) for x in f.readline().split(" ")]
read_usage = [int(x) for x in f.readline().split(" ")]

#print(genome)
#print(read_usage)
#print(fitness_score)

reads = []

line = f.readline()

while line:
  reads.append(line.strip())
  line = f.readline()

f.close()

#print (reads)

cursor = 1
solution_as_array = []
solution_indices = read_usage
for i in range(len(reads)):
  if read_usage[genome[i]] == 1:
    r = reads[genome[i]]
    solution_as_array.append(r)
    solution_indices[genome[i]] = cursor
    cursor += len(r)

#print (solution_as_array)
#print (solution_indices)
print( "".join(solution_as_array))

for index in solution_indices:
  print (index)
