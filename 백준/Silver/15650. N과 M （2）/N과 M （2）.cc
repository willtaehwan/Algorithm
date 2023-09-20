#include <iostream>

using namespace std;

int N, M;

int visited[10] = { 0, };
int path[10] = { 0, };
int cnt = 0;
void dfs(int now) {

	if (cnt == M) {
		for (int i = 0; i < cnt; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		int next = i;
		if (now >= next) continue;
		if (visited[i] != 0) continue;

		visited[i] = 1;
		path[cnt] = i;
		cnt++;
		dfs(next);
		visited[i] = 0;
		path[cnt] = 0;
		cnt--;
	}
	
}


int main() {

	cin >> N >> M;

	dfs(0);

	return 0;
}