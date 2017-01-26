# qualification_bioinformatics_contest_2017

# GA
To prepare input files:
**(Files in inputs/ are already cleaned)**
```bash
apt install dos2unix
dos2unix FILES
```

To run:
```bash
./mu.sh FILE
```

# Tests / Greedy Algorithm
To run tests:
```bash
clang++ -o tests greedy_algorithm.cpp tests.cpp
./tests
```

Expected output:
```
* Test is_substring()
* Running greedy algorithm on example problem
-> Score: 2
-> Output sequence: ACGT
```
