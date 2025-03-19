#include <iostream>
#include <vector>
using namespace std;

string str;
bool DP[2501][2501];
int sDP[2501] = { 0, };
vector<int> v[2501];

void dp_check(int s, int e) {
	int k = 1;
	int l = s;
	int r = e;
	while (1) {
		if (l - k < 0 || r + k >= str.size()) break;
		if (str[l - k] != str[r + k]) break;
		DP[l - k][r + k] = true;
		v[r + k].push_back(l - k);
		k++;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	
	for (int i = 0; i < str.size(); i++) {
		DP[i][i] = true;
		v[i].push_back(i);
		dp_check(i, i);
		if (i == 0) continue;
		if (str[i - 1] == str[i]) {
			DP[i - 1][i] = true;
			v[i].push_back(i - 1);
			dp_check(i - 1, i);
		}
	}

	for (int i = 0; i < str.size(); i++) {
		sDP[i] = 1e9;
		for (int j = 0; j < v[i].size(); j++) {
			int prev = v[i][j] - 1;
			int pre = (prev == -1) ? 0 : sDP[prev];
			sDP[i] = min(sDP[i], pre + 1);
		}
	}

	cout << sDP[str.size()-1];

	return 0;
}