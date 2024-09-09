#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row;
	int col;
};

int N, M, K;

int map[21][21] = { 0, };

int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 }; //상, 우, 하, 좌

int now_dice[6] = { 1, 6, 3, 4, 5, 2 }; //상, 하, 동, 서, 남, 북
Node nc = { 0,0 };
int n_dir = 1;
int tot_sum = 0;

int dice_n[4][6] = {
	{4, 5, 2, 3, 1, 0}, //북
	{3, 2, 0, 1, 4, 5}, //동
	{5, 4, 2, 3, 0, 1}, //남
	{2, 3, 1, 0, 4, 5}  //서
	
};

void dice_turn(int dir) {

	int temp[6];
	for (int i = 0; i < 6; i++) temp[i] = now_dice[dice_n[dir][i]];
	for (int i = 0; i < 6; i++) now_dice[i] = temp[i];

	return;
}

int bfs(int row, int col, int B) {
	
	bool visited[21][21] = { 0, };
	
	queue<Node> q;
	q.push({ row,col });
	visited[row][col] = 1;
	
	int cnt = 1;
	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			if (ner < 0 || nec < 0 || ner >= N || nec >= M) continue;
			if (visited[ner][nec]) continue;
			if (map[ner][nec] != B) continue;

			visited[ner][nec] = true;
			cnt++;
			q.push({ ner,nec });

		}

	}

	return B * cnt;

}

void calc(int row, int col) {

	int A = now_dice[1];
	int B = map[row][col];

	if (A > B) n_dir = (n_dir + 1) % 4;
	if (A < B) n_dir = (n_dir + 3) % 4;
	
	tot_sum += bfs(row, col, B);

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	

	for (int i = 0; i < K; i++) {
		int ner = nc.row + dr[n_dir];
		int nec = nc.col + dc[n_dir];
		if (ner < 0 || nec < 0 || ner >= N || nec >= M) {
			n_dir = (n_dir + 2) % 4;
			ner = nc.row + dr[n_dir];
			nec = nc.col + dc[n_dir];
		}

		dice_turn(n_dir);
		calc(ner, nec);
		nc = { ner,nec };
		//cout << ner << ", " << nec <<", " << n_dir << "   :    ";
		//for (int i = 0; i < 6; i++) cout << now_dice[i] << " ";
		//cout << '\n';
	}

	cout << tot_sum;

	return 0;
}