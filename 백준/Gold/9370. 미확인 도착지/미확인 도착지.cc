#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

#define MAX_LEN 5000002

using namespace std;


struct Node {
	int next;
	int cost;

	bool operator<(Node left) const {
		if (left.cost > cost) return true;
		else return false;
	}
};

int T, n, m, t, s, g, h;

vector<pair<int, int>> map[2010];

int visited[2010] = { 0, };
bool can[2010] = { 0, };

void bfs() {

	for (int i = 1; i <= n; i++) visited[i] = MAX_LEN;

	priority_queue<Node> pq;
	pq.push({ s, 0 });
	visited[s] = 0;

	while (!pq.empty()) {
		Node now = pq.top(); pq.pop();

		for (int i = 0; i < map[now.next].size(); i++) {
			int next = map[now.next][i].first;
			int next_cost = now.cost + map[now.next][i].second;

			if (visited[next] <= next_cost) continue;

			visited[next] = next_cost;
			pq.push({ next,next_cost });
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;

	while (T--) {
		cin >> n >> m >> t;

		cin >> s >> g >> h;

		for (int i = 1; i <= n; i++) vector<pair<int, int>>().swap(map[i]);

		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;

			d *= 2;
			if ((a == g && b == h) || (a == h && b == g)) d -= 1;

			map[a].push_back({ b,d });
			map[b].push_back({ a,d });
		}


		bfs();

		for (int i = 0; i < t; i++) {
			int target;
			cin >> target;

			if (visited[target] % 2 == 1) can[target] = true;
		}

		for (int i = 0; i <= n; i++) {
			if (can[i]) {
				cout << i << " ";
				can[i] = false;
			}
		}

		cout << '\n';
	}

	return 0;
}