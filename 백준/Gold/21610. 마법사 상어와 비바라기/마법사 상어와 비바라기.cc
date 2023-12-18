#include <iostream>
#include <vector>
using namespace std;

int map[51][51] = { 0, };
bool temp[51][51] = { 0, };
int N, M;

struct Node {
	int row;
	int col;
};

int dr[] = { 0,0,-1,-1,-1,0,1,1,1 };
int dc[] = { 0,-1,-1,0,1,1,1,0,-1 };

vector<Node> cloud;


void init() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// 초기 구름 생성
	cloud.push_back({ N - 1,0 });
	cloud.push_back({ N - 1,1 });
	cloud.push_back({ N - 2,0 });
	cloud.push_back({ N - 2,1 });
	return;
}

void cloudMove(int dir, int speed) {

	int Sp = speed % N;

	for (int i = 0; i < cloud.size(); i++) {
		//cout << cloud[i].row << ", " << cloud[i].col << endl;
		// 구름의 다음 위치
		int ner = (cloud[i].row + dr[dir] * Sp + N) % N;
		int nec = (cloud[i].col + dc[dir] * Sp + N) % N;

		map[ner][nec]++; // 구름 이동 후 물 + 1
		temp[ner][nec] = true; // 해당 위치 구름 재생성 방지용 temp
		cloud[i] = { ner,nec }; // 변경된 구름 위치 저장
	}

	for (int i = 0; i < cloud.size(); i++) {

		int ner = cloud[i].row;
		int nec = cloud[i].col;

		// 대각 방향 물 존재 여부 확인
		for (int j = 2; j <= 8; j = j + 2) {
			int cer = ner + dr[j];
			int cec = nec + dc[j];

			if (cer < 0 || cec < 0 || cer >= N || cec >= N) continue;
			if (map[cer][cec] > 0) map[ner][nec]++;
		}

	}

	cloud.clear(); // 구름 정보 초기화

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (temp[i][j]) { // 구름 있던 자리면 재생성 패스
				temp[i][j] = false;
				continue;
			}
			
			if (map[i][j] >= 2) { // 구름 생성
				map[i][j] -= 2;
				cloud.push_back({ i,j });
			}

		}
	}
	
	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	for (int i = 0; i < M; i++) {

		int d, s;
		cin >> d >> s;

		cloudMove(d, s);

		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j]<<" ";
			}
			cout << endl;
		}
		cout << endl;*/
	}
	
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum += map[i][j];
		}
	}

	cout << sum;

	return 0;
}