#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, t;
vector<int> v;
vector<int> c[51];
vector<int> m[51];
bool arr[51] = { 0, };

void bfs() {
	
	queue<int> q;
	q.push(0);
	arr[0] = true;

	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = 0; i < c[now].size(); i++) {
			int next = c[now][i];

			if (arr[next]) continue;

			arr[next] = true;
			q.push(next);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		c[0].push_back(a);
	}

	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		int p = 0;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			m[i].push_back(b);
			if (j == 0) {
				p = b;
				continue;
			}
			c[p].push_back(b);
			c[b].push_back(p);
			p = b;
		}
	}

	bfs();

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		bool flag = true;
		for (int j = 0; j < m[i].size(); j++) {
			if (arr[m[i][j]]) flag = false;
		}
		if (flag) cnt++;
	}
	cout << cnt;

	return 0;
}