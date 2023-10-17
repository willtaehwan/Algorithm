#include <iostream>

using namespace std;

int map[21][21] = { 0, };
int dice[6] = { 0,0,0,0,0,0 }; //[정면, 후면, 좌측, 우측, 상부, 하부]
int dice_1[] = {0,3,2,1,0};
int nextDice[6] = { 0, };
int dr[] = { 0,0,0,-1,1 };
int dc[] = { 0,1,-1,0,0 };

int nextN[4][5] = {
	{0,1,5,4,2},
	{0,1,4,5,3},
	{5,4,2,3,0},
	{4,5,2,3,1}
};

int N, M, x, y, K;

void changeDice(int dir, int changeNum) {
	int nextDice[6] = { 0, };

	for (int i = 0; i < 5; i++) {
		nextDice[i] = dice[nextN[dir-1][i]];
	}
	nextDice[5] = changeNum;

	for (int i = 0; i < 6; i++) {
		dice[i] = nextDice[i];
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int dir;
		cin >> dir;
		int ner = x + dr[dir];
		int nec = y + dc[dir];

		if (ner < 0 || nec < 0 || ner >= N || nec >= M) continue;

		
		int temp = dice[dice_1[dir]];
		if (map[ner][nec] != 0) {
			temp = map[ner][nec];
			map[ner][nec] = 0;
		}
		else {
			map[ner][nec] = temp;
		}
		
		

		for (int i = 0; i < 5; i++) {
			nextDice[i] = dice[nextN[dir - 1][i]];
		}
		nextDice[5] = temp;

		for (int i = 0; i < 6; i++) {
			dice[i] = nextDice[i];
		}

		x = ner; y = nec;

		/*cout << y<<"  "<< x <<"  ////";
		for (int i = 0; i < 6; i++) {
			cout << dice[i] << " ";
		}
		cout << endl;*/
		cout << dice[4] << endl;
	}

	return 0;
}