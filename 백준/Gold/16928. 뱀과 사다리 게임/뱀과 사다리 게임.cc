#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int idx;
	int cnt;
};

int N, M;

int ss[110] = { 0, };
bool visited[110] = { 0, };

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		int a, b;
		cin >> a >> b;
		ss[a] = b;
	}

	queue<Node> q;
	q.push({ 1, 0 });
	visited[1] = true;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		if (now.idx == 100) {
			cout << now.cnt;
			return 0;
		}

		if (now.idx > 100) continue;

		for (int i = 1; i <= 6; i++) {
			int nei = now.idx + i;
			if (ss[nei] != 0) nei = ss[nei];

			if (visited[nei]) continue;

			visited[nei] = true;
			q.push({ nei, now.cnt + 1 });
		}
	}

	return 0;
}