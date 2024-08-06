#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#define INF 1e9
#define MAX 10001
using namespace std;

struct Node {
	int end;
	int cost;
	int time;
};

int T, N, M, K;

int dist[MAX][105] = { 0, };

vector<Node> v[105];

int dp(int nowCost, int nowNode) {
	int ret = dist[nowCost][nowNode];
	if (ret != -1) return ret;
	if (nowNode == N) return 0;

	ret = INF;
	for (int i = 0; i < v[nowNode].size(); i++) {
		Node next = v[nowNode][i];
		if (nowCost >= next.cost) ret = min(ret, dp(nowCost - next.cost, next.end) + next.time);
	}
	dist[nowCost][nowNode] = ret;
	return ret;
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> T;

	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v[a].push_back({ b,c,d });
	}

	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			dist[i][j] = -1;
		}
	}

	int result = dp(M, 1);

	if (result == INF) cout << "Poor KCM";
	else cout << result;

	return 0;
}