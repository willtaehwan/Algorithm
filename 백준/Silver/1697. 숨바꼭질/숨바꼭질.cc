#include <iostream>
#include <queue>

using namespace std;

int N, K;

int visited[100001] = { 0, };



int result;

void bfs(int stNow){

	queue<int> q;
	q.push(stNow);
	visited[stNow] = 1;

	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == K) {
			result = visited[now]-1;
			break;
		}

		for (int i = 0; i < 3; i++) {
			int next;
			if (i == 0) {
				next = now - 1;
			}
			if (i == 1) {
				next = now + 1;
			}
			if (i == 2) {
				next = now * 2;
			}

			if (next < 0 || next > 100000) {
				continue;
			}

			if (visited[next] != 0) {
				continue;
			}

			visited[next] = visited[now] + 1;

			q.push(next);

		}
	}


}

int main() {

	cin >> N >> K;

	bfs(N);

	cout << result;

	return 0;
}