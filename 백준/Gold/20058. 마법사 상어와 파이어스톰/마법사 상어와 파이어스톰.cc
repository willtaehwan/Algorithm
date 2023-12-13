#include <iostream>
#include <queue>
using namespace std;

int map[70][70] = { 0, };
int temp[70][70] = { 0, };
int temp2[70][70] = { 0, };
int visited[70][70] = { 0, };

int map2[70][70] = { 0, };

int N, Q, L;
int Nsize = 2;

int maxSize = 0;

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

struct Node {
	int row;
	int col;
};

void init() {

	cin >> N >> Q;

	for (int i = 1; i < N; i++) Nsize *= 2;
	for (int i = 1; i <= Nsize; i++) {
		for (int j = 1; j <= Nsize; j++) {
			cin >> map[i][j];
		}
	}

}

void rotate(int row, int col, int size) {
	
	int rowC = 0;
	int colC = 0;
	for (int i = row; i < row + size; i++) {
		colC = 0;
		for (int j = col; j < col + size; j++) {
			temp[rowC][colC] = map[i][j];
			colC++;
		}
		rowC++;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			temp2[j][size - i -1] = temp[i][j];
		}
	}
	rowC = 0;
	for (int i = row; i < row + size; i++) {
		colC = 0;
		for (int j = col; j < col + size; j++) {
			map[i][j] = temp2[rowC][colC];
			colC++;
		}
		rowC++;
	}

	return;
}

void fireStorm(int L) {
	int Lsize = 2;

	if (L == 0) return;

	for (int i = 1; i < L; i++) Lsize *= 2;

	for (int i = 1; i <= Nsize; i += Lsize) {
		for (int j = 1; j <= Nsize; j += Lsize) {
			rotate(i,j,Lsize);
		}
	}
	
	return;
}

void iceMelt() {

	for (int i = 1; i <= Nsize; i++) {
		for (int j = 1; j <= Nsize; j++) {
			map2[i][j] = 0;
		}
	}

	for (int i = 1; i <= Nsize; i++) {
		for (int j = 1; j <= Nsize; j++) {
			//cout << map[i][j] << " ";
			int zeroCnt = 0;

			if (map[i][j] == 0) continue;

			for (int k = 0; k < 4; k++) {
				int ner = i + dr[k];
				int nec = j + dc[k];

				if (map[ner][nec] == 0 && map2[ner][nec] == 0) zeroCnt++;

				if (zeroCnt == 2) {
					map[i][j]--;
					if (map[i][j] == 0) map2[i][j] = 1;
					break;
				}

			}

		}
		//cout << endl;
	}

	//cout << endl;

}

void bfs(int row, int col) {

	visited[row][col] = 1;
	queue<Node> q;
	q.push({ row,col });

	int cnt = 1;

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];

			if (visited[ner][nec] != 0) continue;
			if (map[ner][nec] == 0) continue;

			cnt++;
			visited[ner][nec] = cnt;
			q.push({ ner,nec });
		}

	}

	maxSize = max(cnt, maxSize);

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	/*for (int i = 0; i <= Nsize + 1; i++) {
		for (int j = 0; j <= Nsize + 1; j++) {
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';*/

	for (int i = 0; i < Q; i++) {
		cin >> L;
		//cout << L<<"========================================"<<endl;
		fireStorm(L);
		iceMelt();

		/*cout << endl;
		for (int i = 1; i <= Nsize; i++) {
			for (int j = 1; j <= Nsize; j++) {
				cout << map[i][j]<<" ";
			}
			cout << endl;
		}*/

	}

	int sumIce = 0;

	for (int i = 1; i <= Nsize; i++) {
		for (int j = 1; j <= Nsize; j++) {
			//cout << map[i][j] << " ";
			sumIce += map[i][j];
			if (visited[i][j] == 0 && map[i][j] != 0) bfs(i, j);
		}
		//cout << '\n';
	}

	cout << sumIce<<'\n';
	cout << maxSize;


	return 0;
}