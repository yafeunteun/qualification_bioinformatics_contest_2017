#include <iostream>
#include <vector>
#include <string>
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
