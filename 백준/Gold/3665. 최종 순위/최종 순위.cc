#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int T, N, M;
bool map[501][501] = { 0, };
int pre_rank[501] = { 0, };
int arr[501] = { 0, };
int now_rank[501] = { 0, };

/*
void rank_search() {

	stack<int> result;
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (arr[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();

		result.push(now);

		for (int i = 1; i <= N; i++) {
			if (map[now][i] == 0) continue;
			if (arr[i] > 1) arr[i]--;
			else q.push(i);
		}
	}
}*/

void init() {
	cin >> N;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			map[i][j] = 0;
		}
	}
	for (int i = 0; i <= N; i++) {
		now_rank[i] = -1;
		arr[i] = 0;
	}
	for (int i = 0; i < N; i++) cin >> pre_rank[i];
	
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int t = pre_rank[i];
			int n = pre_rank[j];
			map[t][n] = 1;
			arr[t]++;
		}
	}
}

int main() {

	cin >> T;
	for (int tc = 0; tc < T; tc++) {

		init();
		cin >> M;
		bool flag = true;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			if (map[a][b]) {
				map[b][a] = 1;
				map[a][b] = 0;
				arr[b]++;
				arr[a]--;
			}
			else {
				map[a][b] = 1;
				map[b][a] = 0;
				arr[a]++;
				arr[b]--;
			}
		}


		//for (int i = 1; i <= N; i++) cout << arr[i] << " ";
		//cout << '\n';
		for (int i = 1; i <= N; i++) {
			int r = arr[i];
			if (now_rank[r] != -1) {
				flag = false;
				break;
			}
			now_rank[r] = i;
		}

		if (!flag) {
			//for (int i = N - 1; i >= 0; i--) cout << now_rank[i] << " ";
			cout << "IMPOSSIBLE\n";
		}
		else {
			for (int i = N - 1; i >= 0; i--) cout << now_rank[i]<<" ";
			cout << '\n';
		}

	}

	return 0;
}