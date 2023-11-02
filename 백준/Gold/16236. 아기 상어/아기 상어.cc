#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int map[21][21] = { 0, };

struct Node {
	int row;
	int col;
};

int sizeStat = 2;
int eatCnt = 0;
int moveCnt = 0;

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int routeTime(int der, int dec, Node now1) {

	int visited[21][21] = { 0, };

	queue<Node> q;
	q.push({ now1.row,now1.col });
	visited[now1.row][now1.col] = 1;

	int cnt = 9999;
	while (!q.empty()) {
		Node now = q.front(); q.pop();

		if (now.row == der && now.col == dec) {

			cnt = visited[der][dec] - 1;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];

			if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;
			if (map[ner][nec] > sizeStat) continue;
			if (visited[ner][nec] != 0) continue;

			visited[ner][nec] = visited[now.row][now.col] + 1;

			q.push({ ner,nec });
		}
	}
	
	return cnt;
}

void searchFish(Node now) {

	int min_route_cnt = 4999;
	int ner = 999;
	int nec = 999;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] >= sizeStat || map[i][j] == 0) continue;
			if (min_route_cnt < (abs(now.row - i) + abs(now.col - j))) continue;

			int ans = routeTime(i, j, now);
			if (ans > 500) continue;
			if (min_route_cnt > ans) {
				min_route_cnt = ans;
				ner = i;
				nec = j;
			}
			else if (min_route_cnt == ans) {
				if (ner > i) {
					ner = i;
					nec = j;
				}
				else if (ner == i) {
					if (nec > j) {
						ner = i;
						nec = j;
					}
				}
			}

		}
	}


	if (ner > 900 && nec > 900) return;
	else {
		/*cout << "Node = " << ner << " " << nec << "  ans = ";
		cout << min_route_cnt << "  nowSize = " << sizeStat << " ";
		cout << " eating_cnt = " << eatCnt << endl;*/
		map[ner][nec] = 0;
		moveCnt += min_route_cnt;
		eatCnt++;
		if (eatCnt == sizeStat) {
			sizeStat++;
			eatCnt = 0;
		}
		searchFish({ ner,nec });
	}
	return;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	Node start = { 0,0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				start = { i,j };
				map[i][j] = 0;
			}
		}
	}

	searchFish(start);

	cout << moveCnt;

	return 0;
}