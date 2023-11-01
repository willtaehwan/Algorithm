#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, L, R;
int map[51][51] = { 0, };
int checked[51][51] = { 0, };

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

struct Node {
	int row;
	int col;
};

int flag = 0;

void bfs(Node start) {

	queue<Node> q;
	vector<Node> v;
	q.push(start);
	v.push_back(start);
	checked[start.row][start.col] = 1;

	int sum = map[start.row][start.col];

	while (!q.empty()) {
		Node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ner = now.row + dr[i];
			int nec = now.col + dc[i];
			int result = abs(map[ner][nec] - map[now.row][now.col]);
			if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;
			if (checked[ner][nec] != 0) continue;
			if (result < L || result > R) continue;

			checked[ner][nec] = 1;
			sum += map[ner][nec];
			q.push({ ner,nec });
			v.push_back({ ner,nec });
		}

	}

	int result = sum / v.size();
	//cout << result << "  ";
	for (int i = 0; i < v.size(); i++) {
		map[v[i].row][v[i].col] = result;
	}
	//cout << v.size()<<endl;
	if (v.size() > 1) flag = 1;
}

int main() {

	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int cnt = 0;

	while (1) {
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				checked[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (checked[i][j] != 0) continue;

				bfs({ i,j });

			}
		}
		//cout << flag << endl;
		if (flag == 1) {
			cnt++;
			flag = 0;
			continue;
		}
		else break;

	}

	cout << cnt;

	return 0;

}