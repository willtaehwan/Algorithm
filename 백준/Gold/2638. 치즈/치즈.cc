#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row;
	int col;
};

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int N, M;
bool map[101][101] = { 0, };
bool visited[101][101] = { 0, };

void bfs() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = false;
		}
	}

	queue<Node> q;
	q.push({ 0,0 });

	while(!q.empty()){
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			if (ner < 0 || nec < 0 || ner >= N || nec >= M) continue;
			if (map[ner][nec] == 1)continue;
			if (visited[ner][nec]) continue;

			visited[ner][nec] = true;
			q.push({ ner,nec });
		}

	}

}

bool melt() {
	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {

			if (!map[i][j]) continue;
			flag = true;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ner = i + dr[k];
				int nec = j + dc[k];
				if (visited[ner][nec]) cnt++;
			}

			if (cnt > 1) map[i][j] = false;
		}
	}

	return flag;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	
	int ti = 0;
	while (1){
		bfs();
		if (!melt()) break;
		ti++;
	}

	cout << ti;


	return 0;
}