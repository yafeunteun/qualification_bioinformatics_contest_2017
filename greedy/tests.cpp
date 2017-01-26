#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "assert.h"
#include "greedy_algorithm.hpp"

using namespace std;

struct compare {
    bool operator()(const string& first, const string& second) {
        return first.size() < second.size();
    }
};

int main (int argc, char **argv) {
    string dna = string("TAGCGCGT");
    string read;
    compare c;
    int pos;

    cout << "* Test is_substring()" << endl;

    // Invalid read
    read = string("AKC");
    pos = is_substring(dna, read, 0);
    assert(pos == -1);

    // Zero-length read
    read = string("");
    pos = is_substring(dna, read, 0);
    assert(pos == -1);

    // Zero-length dna with > 0 start pos
    string dna_zero = string("");
    read = string("AC");
    pos = is_substring(dna, read, 2);
    assert(pos == -1);

    // Valid read
    read = string("AC");
    pos = is_substring(dna, read, 0);
    assert(pos == 3);

    // Valid read but "too late" in dna
    read = string("AC");
    pos = is_substring(dna, read, 4);
    assert(pos == -1);

    // Read longer than dna
    read = string("TAGCGCGTTAGCGCGT");
    pos = is_substring(dna, read, 0);
    assert(pos == -1);

    cout << "* Running greedy algorithm on example problem" << endl;
    dna = string("TAGCGCGT");

    // Pre-sorted reads
    vector<string> reads = vector<string>();
    reads.push_back("AC");
    reads.push_back("GT");
    reads.push_back("CGCG");

    vector<string> result = vector<string>();
    greedy_algorithm(dna, reads, result);
    cout << "-> Score: " << result.size() << endl;
    cout << "-> Output sequence: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;

    for (int i = 1; i <= 10; i++) {
        ostringstream oss;
        oss << i;
        string path = "../inputs/" + oss.str();
        cout << "* Running greedy algorithm on " << path << endl;
        load_problem(path, dna, reads);
        sort(reads.begin(), reads.end(), c);
        greedy_algorithm(dna, reads, result);
        cout << "-> Score: " << result.size() << endl;
    }
    return 0;
}