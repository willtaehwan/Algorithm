#include <iostream>
#include <queue>
using namespace std;

int S;
int result = 0;

int map[1051][1051] = { 0, };

struct Node {
	int stat;
	int clip;
};

void bfs(int stNow) {

	queue<Node> q;
	q.push({stNow, 0});
	map[1][0] = 1;

	int flag = 1;
	while (!q.empty()) {
		Node now = q.front(); q.pop();

		if (now.stat == S) {
			result = map[now.stat][now.clip]-1;
			break;
		}

		for (int i = 0; i < 3; i++) {
			int nstat = now.stat;
			int nclip = now.clip;
			if (i == 0) {
				if (flag == 0) {
					continue;
				}
				else {
					nclip = nstat;
					flag = 0;
				}
				
			}
			else if (i == 1) {
				if (now.clip <= 0) {
					continue;
				}
				else {
					nstat += nclip;
					flag = 1;
				}
			}
			else if (i == 2) {
				if (nstat <= 0) {
					continue;
				}
				else {
					nstat = nstat - 1;
					flag = 1;
				}
			}
			if (nstat < 0 || nclip < 0) {
				continue;
			}

			if (nstat > S +50 || nclip > S + 50) {
				continue;
			}

			if (map[nstat][nclip] != 0) {
				continue;
			}

			map[nstat][nclip] = map[now.stat][now.clip] + 1;

			q.push({ nstat,nclip });

		}
	}
}

int main() {

	cin >> S;

	bfs(1);

	cout << result;

	return 0;
}