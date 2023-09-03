#include <iostream>
#include <queue>

using namespace std;

int M, N, H;
int map[101][101][101];
int visited[101][101][101] = { 0, };
struct Node {
	int height;
	int row;
	int col;
};

Node tomap[1000001];
int toMcnt = 0;


void bfs(Node start) {
	//cout << "start" << endl;
	queue<Node> q;
	q.push(start);

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		int dr[] = { -1,1,0,0,0,0 };
		int dc[] = { 0,0,-1,1,0,0 };
		int dz[] = { 0,0,0,0,-1,1 };
		for (int i = 0; i < 6; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			int nez = now.height + dz[i];
			
			

			if (ner < 0 || nec < 0 || ner >= N || nec >= M || nez < 0 || nez >= H) {
				continue;
			}

			
			if (map[nez][ner][nec] == -1) {
				continue;
			}
			
			if (visited[nez][ner][nec] <= visited[now.height][now.row][now.col] + 1 
				&& visited[nez][ner][nec] != 0) {
				continue;
			}

			

			visited[nez][ner][nec] = visited[now.height][now.row][now.col] + 1;

			q.push({ nez,ner,nec });
			
		}
	}

}

int main() {

	cin >> M >> N >> H;
	
	for (int z = 0; z < H; z++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[z][i][j];
				if (map[z][i][j] == 1) {
					tomap[toMcnt++] = {z,i,j};
					visited[z][i][j] = 1;
				}
				else if (map[z][i][j] == -1) {
					visited[z][i][j] = -1;
				}
			}
		}
	}

	for (int i = 0; i < toMcnt; i++) {
		bfs(tomap[i]);
	}

	

	int flag = 0;
	int max_score = 0;
	for (int z = 0; z < H; z++) {
		if (flag == 1) {
			break;
		}
		for (int i = 0; i < N; i++) {
			if (flag == 1) {
				break;
			}
			for (int j = 0; j < M; j++) {
				//cout << visited[z][i][j] << " ";
				if (visited[z][i][j] == 0) {
					flag = 1;
					break;
				}
				if (max_score < visited[z][i][j]) {
					max_score = visited[z][i][j];
				}
			}
			//cout << endl;
		}
		//cout << endl;
	}

	if (flag == 1) {
		cout << -1;
	}
	else {
		cout << max_score-1;
	}

	return 0;
}