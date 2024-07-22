#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row;
	int col;
};

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int w, h;
int map[21][21] = { 0, };

Node dirty[12] = { 0, };
int dp[12][12] = { 0, };
int cnt = 2;

bool check_arr[12] = { 0, };
int min_result = 1e9; 


void dfs(int now, int res, int dep) {

	if (res > min_result) return;

	if (dep == cnt - 2) {
		if (min_result > res) min_result = res;
		return;
	}

	for (int i = 2; i < cnt; i++) {
		if (check_arr[i]) continue;
		if (dp[now][i] == 999) continue;
		int next = res + dp[now][i];
		check_arr[i] = true;
		dfs(i, next, dep + 1);
		check_arr[i] = false;
	}
}

void near_search(Node st, int num) {
	for (int i = 0; i < cnt; i++) dp[num][i] = 999;
	int visited[21][21] = { 0, };
	
	queue<Node> q;
	q.push(st);
	visited[st.row][st.col] = 1;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			if (ner < 0 || nec < 0 || ner >= h || nec >= w) continue;
			if (map[ner][nec] == -1) continue;
			if (visited[ner][nec] != 0) continue;
			
			if (map[ner][nec] > 0) {
				if (dp[num][map[ner][nec]] > visited[now.row][now.col]) {
					dp[num][map[ner][nec]] = visited[now.row][now.col];
				}
			}

			visited[ner][nec] = visited[now.row][now.col] + 1;

			q.push({ ner, nec});
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		min_result = 1e9;
		cnt = 2;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char now;
				cin >> now;
				if (now == 'o') {
					dirty[1] = { i,j };
					map[i][j] = 1;
				}
				else if (now == '*') {
					dirty[cnt] = { i,j };
					map[i][j] = cnt++;
				}
				else if (now == 'x') map[i][j] = -1;
				else map[i][j] = 0;
			}
		}

		for(int i = 1; i<cnt;i++) near_search(dirty[i], i);

		check_arr[1] = true;
		dfs(1, 0, 0);
		
		if (min_result >= 1e9) cout << -1<<'\n';
		else cout << min_result << '\n';

	}

	return 0;
}