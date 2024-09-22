#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct Node {
	int c;
	int prev;
};

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

Node dist[1001];

void dk(int st, int ed) {

	for (int i = 1; i <= N; i++) dist[i].c = 1e9;

	priority_queue<Edge> pq;
	pq.push({ st,0 });
	dist[st].c = 0;

	while (!pq.empty()) {
		Edge now = pq.top(); pq.pop();

		if (now.c > dist[now.e].c) continue;

		for (int i = 0; i < v[now.e].size(); i++) {
			Edge next = v[now.e][i];
			int nec = now.c + next.c;
			if (nec >= dist[next.e].c) continue;

			dist[next.e].c = nec;
			dist[next.e].prev = now.e;
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

	int l_cnt = 1;
	int now = ed;
	stack<int> s;
	s.push(now);
	while (1) {
		if (now == st) break;
		now = dist[now].prev;
		s.push(now);
		l_cnt++;
	}

	cout << dist[ed].c<<'\n';
	cout << l_cnt<<'\n';
	while (!s.empty()) {
		int ele = s.top(); s.pop();
		cout << ele << " ";
	}

	return 0;
}