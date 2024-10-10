#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

struct Node {
	int cost;
	int end;

	bool operator<(Node right) const {
		if (cost > right.cost) return true;
		else return false;
	}
};

int tc, n, d, c;

vector<Node> v[10001];
int visited[10001] = { 0, };
void init() {
	
	cin >> n >> d >> c;
	
	for (int i = 1; i <= n; i++) {
		v[i].clear();
		visited[i] = INF;
	}
	for (int i = 0; i < d; i++) {
		int a, b, s;
		cin >> a >> b >> s;
		v[b].push_back({ s, a });
	}
}

void bfs(int st) {

	priority_queue<Node> q;
	q.push({ 0, st });
	visited[st] = 0;

	while (!q.empty()) {
		Node now = q.top(); q.pop();

		if (now.end != st && visited[now.end] < now.cost) continue;

		for (int i = 0; i < v[now.end].size(); i++) {
			Node next = v[now.end][i];
			
			int ne_cost = visited[now.end] + next.cost;
			if (ne_cost >= visited[next.end]) continue;

			visited[next.end] = ne_cost;
			
			q.push({ ne_cost, next.end });

		}
	}
	int cnt = 0;
	int max_result = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i] != INF) {
			cnt++;
			if (max_result < visited[i]) max_result = visited[i];
		}
	}

	cout << cnt << " " << max_result << '\n';

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		init();
		/*cout << "N = " << n << '\n';
		for (int i = 1; i <= n; i++) {
			cout << i << " : ";
			for (int j = 0; j < v[i].size(); j++) {
				cout << v[i][j].next << " ";
			}
			cout << '\n';
		}*/
		bfs(c);

	}

	return 0;
}