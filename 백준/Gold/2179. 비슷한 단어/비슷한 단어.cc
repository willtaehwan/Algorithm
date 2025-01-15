#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;

string s[20002];
int N;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int max_len = 0;
	int max_a = 0;
	int max_b = 0;
	for (int i = 1; i <= N; i++) {
		cin >> s[i];

		for (int j = 1; j <= s[i].size(); j++) {
			string temp = "";
			for (int k = 0; k < j; k++) temp.push_back(s[i][k]);
		
			if (um.find(temp) == um.end()) um.insert({ temp, i });
			else {
				if (max_len < temp.size()) {
					max_len = temp.size();
					max_a = um[temp];
					max_b = i;
				}
				else if (max_len == temp.size() && max_a > um[temp]) {
					max_a = um[temp];
					max_b = i;
				}
			}
		}
	}

	cout << s[max_a] << "\n";
	cout << s[max_b];


	return 0;
}