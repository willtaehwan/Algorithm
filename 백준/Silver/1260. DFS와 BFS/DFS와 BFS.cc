#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

int N, M, V;

vector<int> v[1001];

int visited_dfs[1001] = { 0, };
int visited_bfs[1001] = { 0, };

int path_dfs[1001] = { 0, };
int path_bfs[1001] = { 0, };

int cnt_dfs = 0;
int cnt_bfs = 0;

void dfs(int now) {


	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];

		if (visited_dfs[next] != 0) {
			continue;
		}

		visited_dfs[next] = 1;
		path_dfs[cnt_dfs++] = next;
		dfs(next);
		
		//path_dfs[--cnt_dfs] = 0;

	}
}

void bfs(int start) {

	queue<int> q;
	q.push(start);
	path_bfs[cnt_bfs++] = start;
	visited_bfs[start] = 1;

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < v[now].size(); i++) {

			int next = v[now][i];

			if (visited_bfs[next] != 0) {
				continue;
			}

			visited_bfs[next] = visited_bfs[now] + 1;
			path_bfs[cnt_bfs++] = next;

			q.push(next);

		}

	}

}

int main() {

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {

		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	for (int i = 0; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}

	visited_dfs[V] = 1;
	path_dfs[cnt_dfs++] = V;
	dfs(V);
	
	for (int i = 0; i < cnt_dfs; i++) {
		cout << path_dfs[i] << " ";
	}
	cout << endl;

	bfs(V);

	for (int i = 0; i < cnt_bfs; i++) {
		cout << path_bfs[i] << " ";
	}

	return 0;
}