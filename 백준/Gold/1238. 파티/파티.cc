#include<iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int to;
	int cost;
};

int N, M, X;
vector<Edge> gov[1001];
vector<Edge> rev[1001];

int* dk(vector<Edge> (*v)[1001]) {
	int* visited = new int[N+1];
	for (int i = 0; i <= N; i++) visited[i] = 1e9;

	queue<Edge> q;
	q.push({ X, 0 });
	visited[X] = 0;

	while (!q.empty()) {
		Edge now = q.front(); q.pop();

		if (now.cost > visited[now.to]) continue;

		for (int i = 0; i < (*v)[now.to].size(); i++) {
			Edge next = (*v)[now.to][i];
			int nc = now.cost + next.cost;
			if (visited[next.to] <= nc) continue;
			visited[next.to] = nc;
			q.push({ next.to, nc });
		}
	}

	return visited;
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		gov[a].push_back({ b,c });
		rev[b].push_back({ a,c });
	}
	
	int* tox = dk(&gov);
	int* xto = dk(&rev);

	int ans = 0;
	for (int i = 1; i <= N; i++) ans = max(ans, tox[i] + xto[i]);
	cout << ans;

	return 0;
}