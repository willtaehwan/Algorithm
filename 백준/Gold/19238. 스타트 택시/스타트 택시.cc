#include <iostream>
#include <queue>

using namespace std;

int N, M, oil;

struct Node {
	int row;
	int col;
};

struct sgNode {
	int num;
	int row;
	int col;
};

Node taxi;

struct goCost {
	Node start;
	int cost;
};

sgNode map[21][21] = { 0, };
//int gmap[21][21] = { 0, };

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };



void init() {

	cin >> N >> M >> oil;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int wall;
			cin >> wall;
			if (wall == 1) map[i][j].num = -1;
		}
	}


	cin >> taxi.row >> taxi.col;

	taxi.row -= 1;
	taxi.col -= 1;

	for (int i = 1; i <= M; i++) {
		int mr, mc, gr, gc;
		cin >> mr >> mc >> gr >> gc;
		map[mr - 1][mc - 1] = { i,gr - 1,gc - 1 };

	}

}

goCost searchGet(Node ts) {

	int visited[21][21] = { 0, };
	queue<Node> q;
	q.push(ts);
	visited[ts.row][ts.col] = 1;
	int min_rate = 999;
	int minrow = 0;
	int mincol = 0;
	while (!q.empty()) {
		Node now = q.front(); q.pop();

		if (visited[now.row][now.col] > min_rate) break;

		if (map[now.row][now.col].num > 0) {
			//cout << now.row<<" "<<now.col <<" "<<minrow<<" "<<mincol<< endl;
			if (min_rate > visited[now.row][now.col]) {
				min_rate = visited[now.row][now.col];
				minrow = now.row;
				mincol = now.col;
				//cout << "type1" << endl;
			}
			else {
				if (minrow > now.row) {
					minrow = now.row;
					mincol = now.col;
					//cout << "type2" << endl;
				}
				else if (minrow == now.row && mincol > now.col) {
					minrow = now.row;
					mincol = now.col;
					//cout << "type3" << endl;
				}


			}
		}

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];

			if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;

			if (visited[ner][nec] != 0) continue;

			if (map[ner][nec].num == -1) continue;

			visited[ner][nec] = visited[now.row][now.col] + 1;

			q.push({ ner,nec });

		}

	}
	/*cout << "#####" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << "#####" << endl;*/
	//cout << " last Pick = " << minrow << " " << mincol << endl;
	return { {minrow, mincol}, min_rate - 1 };

}

goCost searchGoal(Node goal) {

	int gor = map[goal.row][goal.col].row;
	int goc = map[goal.row][goal.col].col;
	int visited[21][21] = { 0, };
	queue<Node> q;
	q.push(goal);
	visited[goal.row][goal.col] = 1;
	int cost = 0;
	int finrow = 0;
	int fincol = 0;
	while (!q.empty()) {
		Node now = q.front(); q.pop();

		if (now.row == gor && now.col == goc) {
			cost = visited[now.row][now.col];
			finrow = now.row;
			fincol = now.col;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];

			if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;

			if (visited[ner][nec] != 0) continue;

			if (map[ner][nec].num == -1) continue;

			visited[ner][nec] = visited[now.row][now.col] + 1;

			q.push({ ner,nec });

		}


	}

	/*cout << "#####" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << "#####" << endl;*/


	return { {finrow,fincol},cost - 1 };

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	for (int i = 0; i < M; i++) {

		/*cout << "========승객=========" << endl;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cout << map[y][x] << " ";
			}
			cout << endl;
		}
		cout << "========목적=========" << endl;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				cout << gmap[y][x] << " ";
			}
			cout << endl;
		}
		cout << "=====================" << endl;*/

		// 가장 가까운 승객의 위치 탐색
		goCost goal = searchGet(taxi);
		//cout <<"search man  " << goal.start.row << " " << goal.start.col << " cost : " << goal.cost << endl;


		// 승객이 있지만 벽에 막혀 못갈 경우
		if (goal.cost > 900) {
			oil = -1;
			break;
		}

		// 목적지 까지 거리 탐색
		goCost ans = searchGoal(goal.start);

		//cout << "search goal  " << ans.start.row << " " << ans.start.col << " cost : " << ans.cost << endl;

		if (ans.cost == -1) {
			oil = -1;
			break;
		}
		// 못가면 운행종료 -1 출력
		if (oil < ans.cost + goal.cost) {
			oil = -1;
			break;
		}

		oil = oil + ans.cost - goal.cost;

		//cout << "now oil : " << oil << endl;
		//cout << endl;

		taxi = ans.start;
		map[goal.start.row][goal.start.col] = { 0,0,0 };

	}

	cout << oil;


	return 0;
}