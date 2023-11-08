#include <iostream>
#include <map>
#include <string>
using namespace std;

int N, M;

map<string, int> m;
string m2[100001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string row;
		cin >> row;
		m.insert({row,i});
		m2[i] = row;
	}
	
	for (int i = 0; i < M; i++) {
		string row;
		cin >> row;
		if (row[0] >= '0' && row[0] <= '9') {
			cout << m2[stoi(row)] << "\n";
		}
		else {
			cout << m[row] << "\n";
		}
	}

	return 0;
}