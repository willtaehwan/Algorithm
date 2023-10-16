#include <iostream>
#include <queue>
using namespace std;

int N, K, L;
int map[101][101] = { 0, };
int visited[101][101] = { 0, };
int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
int DAT[10001] = { 0, };

struct directChange {
	int sec;
	int dir;
};

vector <directChange> v;


struct Node {
	int row;
	int col;
};

int bfs() {

	int cnt = 0;
	queue<Node> q;
	q.push({ 0,0 });
	int nowRow = 0;
	int nowCol = 0;
	visited[0][0] = 1;
	int nowdr = 1;
	while (1) {
		if (DAT[cnt] == 1) nowdr = (nowdr + 3) % 4;
		else if (DAT[cnt] == 2) nowdr = (nowdr + 1) % 4;

		int ner = nowRow + dr[nowdr];
		int nec = nowCol + dc[nowdr];

		if (ner < 0 || nec < 0 || ner >= N || nec >= N) break;

		if (visited[ner][nec] == 1) break;

		visited[ner][nec] = 1;
		q.push({ ner,nec });
		nowRow = ner;
		nowCol = nec;

		if (map[ner][nec] != 1) {
			Node tail = q.front(); q.pop();
			visited[tail.row][tail.col] = 0;
		}
		else {
			map[ner][nec] = 0;
		}
		//cout << "================"<<cnt+1<<endl;
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << visited[i][j]<<" ";
			}
			cout << endl;
		}*/

		cnt++;

	}

	return cnt;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		map[y-1][x-1] = 1;
	}
	cin >> L;

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << " == = = = = = == "<<endl;*/

	for (int i = 0; i < L; i++) {
		int a, dr;
		char d;
		cin >> a >> d;
		if (d == 'L') DAT[a] = 1;
		else DAT[a] = 2;

	}


	int result = bfs();

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/

	cout << result + 1;

	return 0;
}