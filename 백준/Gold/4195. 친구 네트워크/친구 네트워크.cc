#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> um;

int T, N;

int par[200010] = { 0, };
int num[200010] = { 0, };

int Find(int a) {
	if (par[a] == a) return a;
	else return par[a] = Find(par[a]);
}

void Union(int a, int b) {

	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA == rootB) return;

	par[rootB] = rootA;
	num[rootA] += num[rootB];
}

int main() {

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;
		um.clear();
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			string str1, str2;
			cin >> str1 >> str2;
			
			if (um.find(str1) == um.end()) {
				par[cnt] = cnt;
				num[cnt] = 1;
				um.insert({ str1, cnt++ });
			}
			if (um.find(str2) == um.end()) {
				par[cnt] = cnt;
				num[cnt] = 1;
				um.insert({ str2, cnt++ });
			}

			int a = um[str1];
			int b = um[str2];

			Union(a, b);

			cout << num[Find(a)] << "\n";
		}
		//for (auto it : um) cout << it.first << " : " << it.second << '\n';
	}
	return 0;
}