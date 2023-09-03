#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int map[26][26] = { 0, };
int visited[26][26] = { 0, };
int DAT[500] = { 0, };
struct Node {
	int row;
	int col;
};

int cnt=0;

void bfs(int stRow, int stCol) {

	queue<Node> q;
	q.push({ stRow,stCol });
	visited[stRow][stCol] = cnt;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		int dr[] = { -1,1,0,0 };
		int dc[] = { 0,0,-1,1 };
		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			
			if (ner < 0 || nec < 0 || ner >= N || nec >= N) {
				continue;
			}

			if (visited[ner][nec] != 0) {
				continue;
			}

			if (map[ner][nec] == 0) {
				continue;
			}

			visited[ner][nec] = cnt;
			DAT[cnt]++;

			q.push({ ner,nec });


		}
	}

}


int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < N; j++) {
			map[i][j] = int(row[j] - '0');
		}
	}

	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && visited[i][j]  == 0) {
				cnt++;
				DAT[cnt]++;
				bfs(i, j);
			}
		}
	}
	
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}*/


	cout << cnt << endl;

	sort(DAT+1, DAT + cnt+1);

	for (int i = 1; i <= cnt; i++) {
		cout << DAT[i] << endl;
	}

	return 0;
}