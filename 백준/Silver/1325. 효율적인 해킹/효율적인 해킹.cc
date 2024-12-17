#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

vector<int> v[10001];
int dp[10001] = { 0, };
bool visited[10001] = { 0, };
int cnt = 0;


void dfs(int now, int rt) {

	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (visited[next]) continue;

		visited[next] = true;
		dp[rt]++;
		dfs(next, rt);
		visited[next] = false;
		
	}

}

void bfs(int st) {

	for (int i = 0; i <= N; i++) visited[i] = 0;

	queue<int> q;
	q.push(st);
	visited[st] = 1;

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (visited[next]) continue;

			dp[st]++;
			visited[next] = true;
			q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	int max_result = 0;
	for (int i = 1; i <= N; i++) {
		bfs(i);
		max_result = max(max_result, dp[i]);
	}

	for (int i = 1; i <= N; i++) {
		if (max_result == dp[i]) cout << i << " ";
	}

	return 0;
}