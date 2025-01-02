#include <iostream>
#include <vector>
using namespace std;

int T, K;
string W;

void find_result() {

	vector<int> v[26];

	for (int i = 0; i < W.size(); i++) {
		int now = W[i] - 'a';
		v[now].push_back(i);
	}

	int min_result = 1e9;
	int max_result = 0;
	for (int i = 0; i < 26; i++) {
		if (v[i].size() < K) continue;
		for (int j = 0; j <= v[i].size() - K; j++) {
			int len = v[i][j + K - 1] - v[i][j] + 1;
			min_result = min(min_result, len);
			max_result = max(max_result, len);
		}
	}

	if (max_result == 0) cout << -1 << '\n';
	else cout << min_result << " " << max_result << '\n';
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> W >> K;
		find_result();
	}

	return 0;
}