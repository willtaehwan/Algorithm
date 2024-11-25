#include <iostream>
using namespace std;

int T, N, M;
int pre_rank[501] = { 0, };
int arr[501] = { 0, };
int now_rank[501] = { 0, };

void init() {
	cin >> N;
	for (int i = 0; i <= N; i++) now_rank[i] = -1;
	
	for (int i = N-1; i >= 0; i--) {
		int t;
		cin >> t;
		pre_rank[t] = i;
		arr[t] = i;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {

		init();
		cin >> M;
		bool flag = true;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			if (pre_rank[a] > pre_rank[b]) {
				arr[a]--;
				arr[b]++;
			}
			else {
				arr[a]++;
				arr[b]--;
			}
		}

		for (int i = 1; i <= N; i++) {
			if (now_rank[arr[i]] != -1) flag = false;
			now_rank[arr[i]] = i;
		}

		if (!flag) cout << "IMPOSSIBLE\n";
		else {
			for (int i = N - 1; i >= 0; i--) cout << now_rank[i]<<" ";
			cout << '\n';
		}
	}

	return 0;
}