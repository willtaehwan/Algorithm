#include <iostream>

using namespace std;

int N;

struct Node {
	int nor;
	int noc;
};

int map[6][3][3] = { // U0 D1 R2 L3 F4 B5
	{{0,0,0},{0,0,0},{0,0,0}},
	{{1,1,1},{1,1,1},{1,1,1}},
	{{2,2,2},{2,2,2},{2,2,2}},
	{{3,3,3},{3,3,3},{3,3,3}},
	{{4,4,4},{4,4,4},{4,4,4}},
	{{5,5,5},{5,5,5},{5,5,5}}
};

int dr1[] = { 0,2,2,0 };
int dc1[] = { 0,0,2,2 };
int dr2[] = { 0,1,2,1 };
int dc2[] = { 1,0,1,2 };

int turn[6][5] = {
	{4,2,5,3,4}, // 예외 처리 X
	{4,3,5,2,4}, // 예외 처리 X
	{0,4,1,5,0}, // B면 입출력 예외 처리
	{0,5,1,4,0}, // B면 입출력 예외 처리
	{0,3,1,2,0}, // L,D 예외 처리
	{0,2,1,3,0} // 예외 처리
};

Node nextNode[6][3][4] = { //shape :  : col
	{  { {0,0},{0,0},{0,0},{0,0} }, { {0,1},{0,1},{0,1},{0,1} }, { {0,2},{0,2},{0,2},{0,2} }  },
	{  { {2,0},{2,0},{2,0},{2,0} }, { {2,1},{2,1},{2,1},{2,1} }, { {2,2},{2,2},{2,2},{2,2} }  },
	{  { {0,2},{0,2},{0,2},{2,0} }, { {1,2},{1,2},{1,2},{1,0} }, { {2,2},{2,2},{2,2},{0,0} }  },
	{  { {0,0},{2,2},{0,0},{0,0} }, { {1,0},{1,2},{1,0},{1,0} }, { {2,0},{0,2},{2,0},{2,0} }  },
	{  { {2,0},{2,2},{0,2},{0,0} }, { {2,1},{1,2},{0,1},{1,0} }, { {2,2},{0,2},{0,0},{2,0} }  },
	{  { {0,0},{0,2},{2,2},{2,0} }, { {0,1},{1,2},{2,1},{1,0} }, { {0,2},{2,2},{2,0},{0,0} }  }
};

void init() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				map[i][j][k] = i;
			}
		}
	}
}

void turnCube(int shape, int dir) {

	int temp1 = map[shape][0][0];
	int temp2 = map[shape][0][1];

	if (dir == 0) {

		for (int i = 0; i < 3; i++) {
			map[shape][dr1[i]][dc1[i]] = map[shape][dr1[i + 1]][dc1[i + 1]];
			map[shape][dr2[i]][dc2[i]] = map[shape][dr2[i + 1]][dc2[i + 1]];
		}
		map[shape][0][2] = temp1;
		map[shape][1][2] = temp2;

		for (int i = 0; i < 3; i++) {
			int temp = map[turn[shape][0]][nextNode[shape][i][0].nor][nextNode[shape][i][0].noc];
			for (int j = 0; j < 3; j++) {
				int nor = nextNode[shape][i][j].nor;
				int noc = nextNode[shape][i][j].noc;
				int ner = nextNode[shape][i][j+1].nor;
				int nec = nextNode[shape][i][j+1].noc;
				map[turn[shape][j]][nor][noc] = map[turn[shape][j + 1]][ner][nec];
			}

			map[turn[shape][3]][nextNode[shape][i][3].nor][nextNode[shape][i][3].noc] = temp;
		}
	}
	else {
		for (int i = 3; i > 0; i--) {
			map[shape][dr1[(i+1)%4]][dc1[(i+1)%4]] = map[shape][dr1[i]][dc1[i]];
			map[shape][dr2[(i+1)%4]][dc2[(i+1)%4]] = map[shape][dr2[i]][dc2[i]];
		}
		map[shape][2][0] = temp1;
		map[shape][1][0] = temp2;

		for (int i = 0; i < 3; i++) {
			int temp = map[turn[shape][0]][nextNode[shape][i][0].nor][nextNode[shape][i][0].noc];
			for (int j = 3; j > 0; j--) {

				int nor = nextNode[shape][i][(j+1)%4].nor;
				int noc = nextNode[shape][i][(j+1)%4].noc;
				int ner = nextNode[shape][i][j].nor;
				int nec = nextNode[shape][i][j].noc;
				map[turn[shape][(j+1)%4]][nor][noc] = map[turn[shape][j]][ner][nec];
			}

			map[turn[shape][1]][nextNode[shape][i][1].nor][nextNode[shape][i][1].noc] = temp;
		}
	}

	return;
}


int main() {

	int TestCase;

	cin >> TestCase;

	for (int tc = 1; tc <= TestCase; tc++) {

		cin >> N;

		init();

		for (int i = 0; i < N; i++) {

			string row;
			cin >> row;

			int dir = 0;
			if (int(row[1]) == 45) dir = 1;


			int shape;
			if (row[0] == 'U') shape = 0;
			else if (row[0] == 'D') shape = 1;
			else if (row[0] == 'L') shape = 3;
			else if (row[0] == 'R') shape = 2;
			else if (row[0] == 'F') shape = 4;
			else shape = 5;
			
			turnCube(shape, dir);

		}
		
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (map[0][j][k] == 0) cout << "w";
				else if (map[0][j][k] == 1) cout << "y";
				else if (map[0][j][k] == 2) cout << "b";
				else if (map[0][j][k] == 3) cout << "g";
				else if (map[0][j][k] == 4) cout << "r";
				else cout << "o";

			}
			cout << endl;
		}
	
	}

	return 0;
}