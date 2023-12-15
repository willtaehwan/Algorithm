#include <iostream>

using namespace std;

int N, M;
int path[10] = { 0, };
int cnt = 0;

void dfs(int now) {

	if (cnt >= M) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		int next = now + i;
		if (next > N) continue;
		path[cnt++] = next;
		dfs(next);
		path[--cnt] = 0;
	}

}

int main() {

	cin >> N >> M;

	dfs(1);

	return 0;
}