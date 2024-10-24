#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
	int x1;
	int y1;
	int x2;
	int y2;
};

int N;

Node p[3001];
bool in_flag = false;

vector<int> v[3001];
bool par[3001] = { 0, };
int cnt = 0;

int ccw(int a, int x, int y) {
	int res1 = (p[a].x2 - p[a].x1) * (y - p[a].y2);
	int res2 = (x - p[a].x2) * (p[a].y2 - p[a].y1);
	if (res1 - res2 < 0) return -1;
	if (res1 - res2 > 0) return 1;

	int low_x = min(p[a].x1, p[a].x2);
	int high_x = max(p[a].x1, p[a].x2);
	int low_y = min(p[a].y1, p[a].y2);
	int high_y = max(p[a].y1, p[a].y2);
	if (low_x <= x && high_x >= x && low_y <= y && high_y >= y) in_flag = true;

	return 0;
}

bool check_cross(int a, int b) {
	bool flag = true;
	if (ccw(a, p[b].x1, p[b].y1) * ccw(a, p[b].x2, p[b].y2) >= 0) flag = false;
	if (ccw(b, p[a].x1, p[a].y1) * ccw(b, p[a].x2, p[a].y2) >= 0) flag = false;

	flag |= in_flag;
	in_flag = false;
	return flag;
}

int bfs(int a) {

	int tot = 1;

	queue<int> q;
	q.push(a);
	par[a] = cnt;
	
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (par[next] != 0) continue;
			par[next] = cnt;
			tot++;
			q.push(next);
		}
	}

	return tot;
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i].x1 >> p[i].y1 >> p[i].x2 >> p[i].y2;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (check_cross(i, j)) {
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}

	int max_result = 0;

	for (int i = 0; i < N; i++) {
		if (par[i] != 0) continue;
		cnt++;
		int ans = bfs(i);
		if (max_result < ans) max_result = ans;
	}

	cout << cnt << '\n';
	cout << max_result;

	return 0;
}