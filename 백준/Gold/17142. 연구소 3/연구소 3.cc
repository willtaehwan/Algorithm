#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int map[51][51] = { 0, };

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

struct Node {
	int row;
	int col;
};

Node virus[10] = { 0, };

vector<Node> v;
int minResult = 9999;
int bfs(Node* virus) {

	int visited[51][51] = { 0, };
	queue<Node> q;
	int maxResult = 0;
	for (int i = 0; i < M; i++) {
		q.push({ virus[i].row,virus[i].col });
		visited[virus[i].row][virus[i].col] = 1;
	}

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];

			if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;

			if (map[ner][nec] == 1) continue;
			if (visited[ner][nec] != 0) continue;

			visited[ner][nec] = visited[now.row][now.col] + 1;
			
			q.push({ ner,nec });

			if (map[ner][nec] == 2) continue;
			maxResult = max(maxResult, visited[ner][nec]);

		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == 0 && map[i][j] == 0) maxResult = 9999;
		}
	}

	//cout << maxResult<<endl;
	return maxResult-1;
}

void dfs(int now, int cnt) {

	if (cnt >= M) {
		

		minResult = min(minResult, bfs(virus));
		
		return;
	}

	for (int i = 0; i < v.size(); i++) {

		if (i <= now && cnt!=0) continue;

		virus[cnt++] = v[i];

		dfs(i, cnt);

		virus[cnt] = { 0,0 };
		cnt--;

	}


}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) v.push_back({ i,j });
		}
	}

	int flag = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) flag = 1;
		}
	}

	if (flag == 1) {
		dfs(0, 0);

		if (minResult > 9990) cout << -1;
		else cout << minResult;
	}
	else {
		cout << 0;
	}

	
	

	return 0;
}