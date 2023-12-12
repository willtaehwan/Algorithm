#include <iostream>

using namespace std;

int map[505][505] = { 0, }; // 모래의 양을 저장하는 2차원 배열
int N; // 맵의 크기
int r, c, d; // 바람의 현재 위치

// 이동 배열, 바람 방향 순서대로 나열 : 좌 -> 하 -> 우 -> 상
int dr[] = { 0,1,0,-1 };
int dc[] = { -1,0,1,0 };

// 바람의 다음 방향 인덱스
int nextdir = 0;

int cccc = 1;

void init() {

	cin >> N;

	// 바람의 시작 위치
	r = N / 2 + 2;
	c = N / 2 + 2;

	// 맵 외부 2칸 Padding하여 초기 모래의 양 저장
	for (int i = 2; i < N+2; i++) {
		for (int j = 2; j < N+2; j++) {
			cin >> map[i][j];
		}
	}

	return;
}

int sandCal(int sand, int num) {
	return (sand * num) / 100;
}

void windmove(int ner, int nec) {
	
	int sand = map[ner][nec];

	map[ner][nec] = 0;

	int dir1 = (nextdir + 3) % 4;
	int dir2 = (nextdir + 1) % 4;
	int dir3 = (nextdir + 2) % 4;

	//cout << nextdir << " " << dir1 << " " << dir2 << " " << dir3 << endl;

	int etc = sand - sandCal(sand, 2) * 2 - sandCal(sand, 7) * 2
		- sandCal(sand, 5) - sandCal(sand, 10) * 2 - sandCal(sand, 1) * 2;

	map[ner + dr[dir1] * 2][nec + dc[dir1] * 2] += sandCal(sand,2);
	map[ner + dr[dir2] * 2][nec + dc[dir2] * 2] += sandCal(sand,2);
	
	map[ner + dr[dir1]][nec + dc[dir1]] += sandCal(sand, 7);
	map[ner + dr[dir2]][nec + dc[dir2]] += sandCal(sand, 7);

	map[ner + dr[nextdir] * 2][nec + dc[nextdir] * 2] += sandCal(sand, 5);
	map[ner + dr[nextdir]][nec + dc[nextdir]] += etc;

	map[ner + dr[dir1] + dr[nextdir]][nec + dc[dir1] + dc[nextdir]] += sandCal(sand, 10);
	map[ner + dr[dir2] + dr[nextdir]][nec + dc[dir2] + dc[nextdir]] += sandCal(sand, 10);

	map[ner + dr[dir1] + dr[dir3]][nec + dc[dir1] + dc[dir3]] += sandCal(sand, 1);
	map[ner + dr[dir2] + dr[dir3]][nec + dc[dir2] + dc[dir3]] += sandCal(sand, 1);

	return;
}

int main() {

	init(); // 값 입력

	int changeDistanceCnt = 0;
	int dirCnt = 0;
	int distance = 1;

	while (r != 2 || c != 2) {

		int ner = r + dr[nextdir];
		int nec = c + dc[nextdir];

		windmove(ner, nec);

		changeDistanceCnt++;
		if (changeDistanceCnt == distance) {
			changeDistanceCnt = 0;
			nextdir = (nextdir + 1) % 4;
			dirCnt++;
		}

		if (dirCnt == 2) {
			dirCnt = 0;
			distance++;
		}


		r = ner;
		c = nec;

	}
	
	int answer = 0;
	for (int i = 0; i < N + 4; i++) {
		for (int j = 0; j < N + 4; j++) {
			//cout << map[i][j] << " ";
			if (i < 2 || i > N+1) {
				answer += map[i][j];
			}
			else if (j<2 || j> N + 1) {
				answer += map[i][j];
			}
		}
		//cout << endl;
	}

	cout << answer;


	return 0;
}