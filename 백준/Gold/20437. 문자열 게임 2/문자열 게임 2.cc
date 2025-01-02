#include <iostream>
#include <vector>
using namespace std;

int T, K;
string W;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> W >> K;

		vector<int> v[26];

		for (int i = 0; i < W.size(); i++) {
			int now = W[i] - 'a';
			v[now].push_back(i);
		}

		int mi = 1e5;
		int ma = 0;
		for (int i = 0; i < 26; i++) {
			if (v[i].size() < K) continue;
			for (int j = 0; j <= v[i].size() - K; j++) {
				int l = v[i][j + K - 1] - v[i][j] + 1;
				mi = min(mi, l);
				ma = max(ma, l);
			}
		}

		if (ma == 0) cout << -1 << '\n';
		else cout << mi << " " << ma << '\n';
	}

	return 0;
}