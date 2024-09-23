#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;



struct Edge {
	int e;
	int c;

	bool operator<(Edge left) const {
		if (c < left.c) return false;
		else return true;
	}
};

int N, M, st, ed;

vector<Edge> v[1001];

int dist[1001];

void dk(int st, int ed) {

	for (int i = 1; i <= N; i++) dist[i] = 1e9;

	priority_queue<Edge> pq;
	pq.push({ st,0 });
	dist[st] = 0;

	while (!pq.empty()) {
		Edge now = pq.top(); pq.pop();

		if (now.c > dist[now.e]) continue;

		for (int i = 0; i < v[now.e].size(); i++) {
			Edge next = v[now.e][i];
			int nec = now.c + next.c;
			if (nec >= dist[next.e]) continue;

			dist[next.e] = nec;
			pq.push({next.e, nec });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		v[s].push_back({ e,c});
	}

	cin >> st >> ed;

	dk(st, ed);

	cout << dist[ed]<<'\n';

	return 0;
}