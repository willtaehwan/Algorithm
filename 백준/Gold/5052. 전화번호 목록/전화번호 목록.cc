#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int T, N;

unordered_map<string, int> um[51];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		cin >> N;

		vector<string> v;

		for (int i = 0; i < N; i++) {
			string a;
			cin >> a;
			v.push_back(a);
			um[tc].insert({ a, 1 });
		}

		bool flag = true;

		for (int i = 0; i < N; i++) {
			string now = v[i];
			
			while (now != "") {
				now.pop_back();
				if (um[tc].find(now) != um[tc].end()) flag = false;
			}
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}