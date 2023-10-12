#include <iostream>
#include <queue>
using namespace std;

int N, M;
char map[15][15] = { 0, };


int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

char dchar[] = { 'U','D','L','R' };

struct Node {
	int redRow;
	int redCol;
	int blueRow;
	int blueCol;
	int count;
};

struct soloNode {

	int row;
	int col;
	int result;
};

Node Ball;

int result = -1;

// 파랑공 같이 들어오는 상황 예외 처리 -> 빨강 파랑 상태를 하나의 구조체로
// 못들어가는 경우 -1 출력

soloNode blue_bfs(int Rrow, int Rcol, int noRow, int noCol, int direct) {

	int Brow = noRow;
	int Bcol = noCol;
	int Bresult = 0;
	int flag = 0;

	if (noRow == Rrow && noCol == Rcol) return { noRow - dr[direct], noCol - dc[direct], 0 };

	for (int k = 1; k < 15; k++) {
		int bner = noRow + dr[direct] * k;
		int bnec = noCol + dc[direct] * k;

		if (bner == Rrow && bnec == Rcol) {

			Brow = bner - dr[direct];
			Bcol = bnec - dc[direct];
			flag = 1;
			break;
		}

		if (map[bner][bnec] == '#' && flag == 0) {

			Brow = bner - dr[direct];
			Bcol = bnec - dc[direct];
			break;
		}

		if (map[bner][bnec] == 'O') Bresult = 1;

	}

	return { Brow, Bcol, Bresult };
}

void bfs(Node st) {

	queue<Node> q;
	q.push({ st.redRow,st.redCol,st.blueRow,st.blueCol,1 });


	int flag = 0;
	while (!q.empty()) {

		Node now = q.front(); q.pop();

		if (flag == 1) break;

		if (now.count > 10) continue;


		for (int i = 0; i < 4; i++) {
			if (flag == 1) break;
			int bluecheck = 0;
			for (int k = 1; k < 15; k++) {
				int rner = now.redRow + dr[i] * k;
				int rnec = now.redCol + dc[i] * k;

				if (now.blueRow == rner && now.blueCol == rnec) bluecheck = 1;

				if (map[rner][rnec] == '#') {

					int chr = rner - dr[i];
					int chc = rnec - dc[i];

					soloNode B = blue_bfs(chr, chc, now.blueRow, now.blueCol, i);

					if (B.result == 1) break;

					//cout << chr << ", " << chc << " / " << B.row << ", " << B.col <<" "<< i <<" " << now.count + 1 << endl;
					// 0:상 1:하 2:좌 3:우
					if (bluecheck == 1) {
						if (B.row != now.redRow || B.col != now.redCol || chr != now.blueRow || chc != now.blueCol) {
							q.push({ B.row, B.col,chr,chc, now.count + 1 });
							//cout <<"BLUE ONN : " << chr << ", " << chc << " / " << B.row << ", " << B.col << " " << dchar[i] << " " << now.count + 1 << endl;
						}
					}
					else {
						if (chr != now.redRow || chc != now.redCol || B.row != now.blueRow || B.col != now.blueCol) {
							q.push({ chr,chc, B.row, B.col, now.count + 1 });
							//cout << "BLUE OFF : " << chr << ", " << chc << " / " << B.row << ", " << B.col << " " << dchar[i] << " " << now.count + 1 << endl;
						}
					}


					break;
				}

				if (map[rner][rnec] == 'O' && flag == 0) {

					soloNode B = blue_bfs(-1, -1, now.blueRow, now.blueCol, i);

					if (B.result == 1) break;
					//cout <<now.blueRow<<" "<<now.blueCol<<" "<< B.row << " " << B.col << "   " << i << endl;
					flag = 1;
					result = now.count;
					break;
				}

			}
		}

	}
}

int main() {

	cin >> N >> M;
	int rr, rc, br, bc;
	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < M; j++) {
			map[i][j] = row[j];
			if (row[j] == 'R') {
				rr = i;
				rc = j;
			}
			if (row[j] == 'B') {
				br = i;
				bc = j;
			}
		}
	}

	Ball = { rr,rc,br,bc };

	bfs(Ball);


	cout << result;

	return 0;
}