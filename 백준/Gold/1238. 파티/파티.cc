#include<iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int to;
	int cost;

	bool operator<(Edge right) const {
		if (cost < right.cost) return true;
		return false;
	}

};

int N, M, X;
int tox[1001] = { 0, };
int xto[1001] = { 0, };
int visited[1001] = { 0, };
vector<Edge> v[1001];

void dk(int st) {

	for (int i = 0; i <= N; i++) visited[i] = 1e9;

	queue<Edge> q;
	q.push({ st, 0 });
	visited[st] = 0;

	while (!q.empty()) {
		Edge now = q.front(); q.pop();

		if (now.cost > visited[now.to]) continue;

		for (int i = 0; i < v[now.to].size(); i++) {
			Edge next = v[now.to][i];
			int nc = now.cost + next.cost;
			if (visited[next.to] <= nc) continue;
			visited[next.to] = nc;
			q.push({ next.to, nc });
		}
	}

	tox[st] = visited[X];
	
	if (st == X) {
		for (int i = 1; i <= N; i++) xto[i] = visited[i];
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	for (int i = 1; i <= N; i++) dk(i);
	
	int ans = 0;

	/*for (int i = 1; i <= N; i++) {
		cout << tox[i] << " ";
	}
	cout << '\n';
	for (int i = 1; i <= N; i++) {
		cout << xto[i] << " ";
	}
	cout << '\n';*/
	for (int i = 1; i <= N; i++) ans = max(ans, tox[i] + xto[i]);
	cout << ans;

	return 0;
}