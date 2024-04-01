#include <iostream>
#include <cstring>
using namespace std;

int cnt = 0;

struct Trie {
	bool finish;
	Trie* next[26];

	Trie() : finish(false) {
		memset(next, 0, sizeof(next));
	}
	
	void insert(const char* key) {
		if (*key == '\0') finish = true;
		else {
			int curr = *key - 'a';
			if (next[curr] == NULL) {
				cnt++;
				next[curr] = new Trie();
			}
			next[curr]->insert(key + 1);
		}
	}

};

Trie A;

char str[1001];

int main() {

	string S;
	cin >> S;
	
	for (int i = 0; i < S.size(); i++) str[i] = S[i];

	for (int i = 0; i < S.size(); i++) {
		A.insert(str+i);
	}

	cout << cnt;

	return 0;
}