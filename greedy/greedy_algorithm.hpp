using namespace std;

int find_pos(string& dna, char c, int start_pos);

int is_substring(string& dna, string& read, int start_pos);

void greedy_algorithm(string& dna, vector<string>& reads, vector<string>& result);