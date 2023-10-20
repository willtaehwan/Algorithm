#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N, K, W;

vector<int> v[1001];

int cost[1001] = { 0, };
int DP[1001] = { 0, };
void init() {
	memset(DP, 0, sizeof(DP));
	memset(cost, 0, sizeof(cost));
	for (int i = 0; i <= N; i++) {
		v[i].clear();
	}

}
void input() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
	}

	for (int i = 0; i < K; i++) {
		int from, to;
		cin >> from >> to;
		v[to].push_back(from);
	}
	cin >> W;
}


int bfs(int stNow) {

	int sum = 0;
	queue<int> q;
	DP[stNow] = cost[stNow];
	q.push(stNow);

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];

			if (DP[next] >= DP[now] + cost[next]) continue;

			DP[next] = DP[now] + cost[next];

			q.push(next);

		}

	}
	int maxChoice = 0;
	for (int i = 1; i <= N; i++) {
		if (maxChoice < DP[i]) {
			maxChoice = DP[i];
		}
	}

	return maxChoice;
}

void solution() {

	cout << bfs(W) << "\n";

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;

	cin >> T;

	for (int tc = 0; tc < T; tc++) {

		init();
		input();
		solution();

	}


	return 0;
}