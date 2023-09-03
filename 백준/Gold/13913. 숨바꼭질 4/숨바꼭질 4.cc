#include <iostream>
#include <queue>

using namespace std;

int N, K;

int visited[100001] = { 0, };
int pathin[100001] = { 0, };
vector<int> path;

int result;

void bfs(int stNow) {

	queue<int> q;
	q.push(stNow);
	visited[stNow] = 1;
	
	while (!q.empty()) {
		int now = q.front(); q.pop();

		if (now == K) {
			result = visited[now] - 1;
			break;
		}

		int dr[3] = { now * 2, now + 1, now - 1 };

		for (int i = 0; i < 3; i++) {
			int next = dr[i];
			
			if (next < 0 || next > 100000) {
				continue;
			}

			if (visited[next] != 0) {
				continue;
			}

			visited[next] = visited[now] + 1;
			pathin[next] = now;
			q.push(next);

		}
	}


}

int main() {

	cin >> N >> K;

	bfs(N);

	cout << result << endl;

	path.push_back(K);

	for (int i = 0; i <= result; i++) {
		path.push_back(pathin[K]);
		K = pathin[K];
	}
	for (int i = result; i >= 0; i--) {
		cout << path[i] << " ";
	}
	

	return 0;
}