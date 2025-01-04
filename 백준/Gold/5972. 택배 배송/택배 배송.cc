#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
	int to;
	int cost;
};

int N, M;

int map[50002] = { 0, };
vector<Node> v[50002];

int bfs() {

	for (int i = 0; i <= N; i++) map[i] = 1e9;

	queue<Node> q;
	q.push({ 1, 0 });
	map[1] = 0;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		if (now.cost > map[now.to]) continue;
		if (now.cost > map[N]) continue;

		for (int i = 0; i < v[now.to].size(); i++) {
			Node next = v[now.to][i];
			int next_cost = next.cost + now.cost;
			if (map[next.to] <= next_cost) continue;

			map[next.to] = next_cost;
			q.push({ next.to, next_cost });
		}
	}

	return map[N];
}

int main() {
	
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	cout<<bfs();

	return 0;
}