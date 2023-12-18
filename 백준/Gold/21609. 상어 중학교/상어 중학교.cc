#include <iostream>
#include <queue>
using namespace std;

int map[21][21] = { 0, };
int visited[21][21] = { 0, };
int temp[21][21] = { 0, };
int N, M;
int finalScore = 0;

struct Node {
	int row;
	int col;
};

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	return;
}

void prin_out() { // 디버깅 용 맵 탐색
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == -2) cout << "# ";
			else if (map[i][j] == -1) cout << "X ";
			else cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void v_clear() { //visited 배열 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
	return;
}

Node bfs(int row, int col, bool del) { // del = 그룹 제거 시 활성화
	int cnt = 1; // 그룹 내 블록 개수
	int rainCnt = 0; // 그룹 내 무지개 블록 개수
	int checkNum = map[row][col]; // 해당 그룹의 기준 번호 저장
	if (del) map[row][col] = -2; // 그룹 제거 시 -2로 변환
	visited[row][col] = 1;
	queue<Node> q;
	q.push({ row,col });

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];

			if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;
			if (visited[ner][nec] != 0) continue;
			if (map[ner][nec] != checkNum && map[ner][nec] != 0) continue;
			if (map[ner][nec] == 0) rainCnt++; //무지개 블록 카운팅
			visited[ner][nec] = 1;
			cnt++; //블록 카운팅
			if (del) map[ner][nec] = -2;
			q.push({ ner,nec });
		}

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) visited[i][j] = 0;
			// 무지개 블록은 다음 BFS에서 체크 되도록 초기화
		}
	}

	if (del) v_clear();

	return { cnt, rainCnt };
}

void gravity() { // 블록 하강

	for (int j = 0; j < N; j++) {
		int last = N - 1;
		for (int i = N - 1; i >= 0; i--) {
			if (map[i][j] == -2) continue;
			if (map[i][j] == -1) {
				last = i - 1;
				continue;
			}

			if (i != last) {
				map[last][j] = map[i][j];
				map[i][j] = -2;
			}
			last--;
		}
	}

	//prin_out();

	return;
}

void rotateR() { //2차원 회전 행렬, temp 값 저장 후 재 반환

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = map[j][N - i - 1];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = temp[i][j];
		}
	}

	//prin_out();

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	//cout << endl;
	//prin_out();

	while (1) {
		int bestScore = 0;
		int bestRain = 0;
		int flag = 0;
		int delrow = 0;
		int delcol = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] <= 0) continue;

				Node ans = bfs(i, j, false);
				if (ans.row < 2) continue;
				else flag = 1;

				if (bestScore < ans.row) flag = 2;

				else if (bestScore == ans.row 
					&& bestRain <= ans.col) flag = 2;

				if (flag == 2) {
					bestScore = ans.row;
					bestRain = ans.col;
					delrow = i;
					delcol = j;
				}

			}
		}
		v_clear();
		finalScore += bestScore * bestScore;
		//cout << "bestScore = " << bestScore << endl;
		if (flag != 0) bfs(delrow, delcol, true);
		else break;

		//prin_out();

		gravity();
		rotateR();
		gravity();

		//cout << "=================================";
		//cout << endl;
	}

	cout << finalScore;

	return 0;
}