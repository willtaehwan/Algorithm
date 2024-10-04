#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;

vector<int> map[202];

int city[1001] = { 0, };
int visited[202] = { 0, };

void bfs(int st) {

	queue<int> q;
	q.push(st);

	visited[st] = st;

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < map[now].size(); i++) {
			int next = map[now][i];
			if (visited[next] != 0) continue;

			visited[next] = st;
			q.push(next);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	cin >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			bool a;
			cin >> a;
			if (a) map[i].push_back(j);
		}
	}
	
	for (int i = 0; i < M; i++) cin >> city[i];
	
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) bfs(i);
	}

	bool flag = true;
	for (int i = 1; i < M; i++) {
		if (visited[city[0]] != visited[city[i]]) {
			flag = false;
			break;
		}
	}

	if (flag) cout << "YES";
	else cout << "NO";

	return 0;
}