#include <iostream>

using namespace std;

int N, M, y,x,d;

int map[51][51] = { 0, };
int visited[51][51] = { 0, };
int dr[] = {-1, 0, 1, 0};
int dc[] = { 0, 1, 0, -1};

int cnt = 0;

void runbot(int nowRow, int nowCol, int nowdir) {
	/*cout << nowRow << " " << nowCol << " " << nowdir << endl;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;*/

	int flag = 0;

	for (int i = 0; i < 4; i++) {
		int ned = (nowdir + 3 - i) % 4;
		int ner = nowRow + dr[ned];
		int nec = nowCol + dc[ned];

		if (visited[ner][nec] == 1 || map[ner][nec] == 1) continue;
		
		if (visited[ner][nec] == 0) {
			visited[ner][nec] = 1;
			cnt++;
			flag = 1;
			runbot(ner, nec, ned);
			break;
		}

	}

	if (flag == 0) {
		int ned = (nowdir + 2) % 4;
		int ner = nowRow + dr[ned];
		int nec = nowCol + dc[ned];

		if (map[ner][nec] == 1) return;
		else {
			runbot(ner, nec, nowdir);
		}
		
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin >> y >> x >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	visited[y][x] = 1;
	cnt++;

	runbot(y,x,d);

	cout << cnt;

	return 0;
}