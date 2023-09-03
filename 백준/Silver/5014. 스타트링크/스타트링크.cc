#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;

int arr[1000001] = { 0, };
int visited[1000001] = { 0, };

void bfs(int stNow) {

	queue<int> q;
	q.push(stNow);
	visited[stNow] = 1;

	while (!q.empty()) {
		int now = q.front(); q.pop();


		int dr[] = { U,D*-1 };
		for (int i = 0; i < 2; i++) {
			int next = now + dr[i];

			if (next <= 0 || next > F) {
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

	cin >> F >> S >> G >> U >> D;

	bfs(S);


	if (visited[G] == 0) {
		cout << "use the stairs";
	}
	else {
		cout << visited[G] - 1;
	}
	

	return 0;
}