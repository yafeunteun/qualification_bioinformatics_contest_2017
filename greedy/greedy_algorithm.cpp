#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "assert.h"
#include "greedy_algorithm.hpp"

using namespace std;

// Returns first position of char `c` in `dna`
// starting at position `start_pos`. -1 if not found.
int find_pos(string& dna, char c, int start_pos) {
  for (int i = start_pos; i < dna.length(); i++) {
    if (dna[i] == c) return i;
  }
  return -1;
}

// Returns position of the last char of `read` in `dna`
// starting at position `start_pos`. -1 if not found.
int is_substring(string& dna, string& read, int start_pos) {
  int last_pos = -1;
  for (int i = 0; i < read.length(); i++) {
    int pos = find_pos(dna, read[i], start_pos);
    if (pos == -1) return -1;
    start_pos = pos + 1;
    last_pos = pos;
  }
  return last_pos;
}

void load_problem(string path, string& dna_out, vector<string>& reads_out) {
  ifstream infile(path);
  string line;
  int size = 0;

  reads_out.clear();

  infile >> dna_out;
  infile >> size;
  
  while(getline(infile, line)) {
    if (line.length() > 0) {
      reads_out.push_back(line);
    }
  }

  assert(reads_out.size() == size);  
}

void greedy_algorithm(string& dna, vector<string>& reads, vector<string>& result) {
  int cursor = 0;

  for (int i = 0; i < reads.size(); i++) {
    int pos = is_substring(dna, reads[i], cursor);

    if (pos != -1) {
      cursor = pos + 1;
      result.push_back(reads[i]);
    }
  }
}
