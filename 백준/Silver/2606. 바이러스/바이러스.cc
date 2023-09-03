#include <iostream>
#include <queue>
using namespace std;

int N, M;
int visited[101] = { 0, };
vector<int> v[101];

void dfs(int now) {

	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];

		if (visited[next] != 0) {
			continue;
		}

		visited[next] = 1;

		dfs(next);

	}

}

int main() {

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	visited[1] = 1;
	dfs(1);

	int insectedPC = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] != 0) {
			insectedPC++;
		}
		//cout << visited[i] << " ";
	}

	cout << insectedPC-1;

	return 0;
}