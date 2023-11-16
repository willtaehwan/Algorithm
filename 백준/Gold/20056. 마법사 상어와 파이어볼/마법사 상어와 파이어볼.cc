#include <iostream>

using namespace std;

int N, M, K;

struct Fire {
	int mass;
	int dir;
	int speed;
	bool stackOn[2];
	int nextdir[2];

};

Fire map[51][51] = { 0, };
Fire temp[51][51] = { 0, };

int dr[] = { -1,-1,0,1,1,1,0,-1 };
int dc[] = { 0,1,1,1,0,-1,-1,-1 };

void init() {

	


	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		map[r - 1][c - 1].mass = m;
		map[r - 1][c - 1].speed = s;
		map[r - 1][c - 1].dir = d;
	}

}

void nextPlace(int i, int j,int flag) {

	Fire now = map[i][j];
	//cout << i << " " << j << " //  ";
	int ned = 0;
	int nem = now.mass;
	if (flag == 8) ned = now.dir;
	else {
		ned = flag;
		nem /= 4;
	}

	int ner = i + dr[ned] * (now.speed % N);
	int nec = j + dc[ned] * (now.speed % N);

	if (ner < 0) ner = N + ner;
	else if (ner >= N) ner = ner - N;

	if (nec < 0) nec = N + nec;
	else if (nec >= N) nec = nec - N;
	//cout << ner << " " << nec << " //  ";
	temp[ner][nec].mass += nem;
	temp[ner][nec].speed += now.speed;
	temp[ner][nec].dir = ned;
	if (ned % 2 == 0) temp[ner][nec].nextdir[0]++;
	else temp[ner][nec].nextdir[1]++;

	return;
}

void moveFireBall() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Fire now = map[i][j];
			if (now.mass == 0) continue;

			if (now.stackOn[0] == 0) {
				nextPlace(i, j, 8);
				map[i][j] = { 0,0,0,{0,0},{0,0} };
			}
			
			if (now.stackOn[0] == 1) {
				// 파이어볼이 겹쳤을 때
				//cout << "HI" << endl;
				if (now.stackOn[1] == 0) {
					// 겹친 파이어볼의 방향이 0 2 4 6
					for (int k = 0; k < 4; k++) nextPlace(i, j, k * 2);
				}
				else {
					// 겹친 파이어볼의 방향이 1 3 5 7
					for (int k = 0; k < 4; k++) nextPlace(i, j, k * 2 + 1);
				}
				map[i][j] = { 0,0,0,{0,0},{0,0} };
			}

		}
	}

}

void sumNdiv() {
	//cout << "======temp======" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//cout << temp[i][j].mass << " ";
			Fire tnow = temp[i][j];
			if (tnow.mass != 0) {

				if (tnow.nextdir[0] + tnow.nextdir[1] > 1) {
					map[i][j].stackOn[0] = 1;

					if (tnow.nextdir[0] != 0 && tnow.nextdir[1] != 0) {
						map[i][j].stackOn[1] = 1;
					}

					map[i][j].mass = (tnow.mass / 5)*4;
					map[i][j].speed = tnow.speed / (tnow.nextdir[0] + tnow.nextdir[1]);
					if(map[i][j].mass == 0) map[i][j] = { 0,0,0,{0,0},{0,0} };
				}
				else {
					map[i][j].mass = tnow.mass;
					map[i][j].speed = tnow.speed;
					map[i][j].dir = tnow.dir;
				}

				temp[i][j] = { 0,0,0,{0,0},{0,0} };

			}
		}
		//cout << endl;
	}
	//cout << endl;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	init();

	for (int i = 0; i < K; i++) {
		moveFireBall();
		sumNdiv();

		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout<<map[i][j].mass<<" ";
			}
			cout << endl;
		}
		cout << endl;*/
	}
	
	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			result += map[i][j].mass;
		}
	}

	cout << result;

	return 0;
}