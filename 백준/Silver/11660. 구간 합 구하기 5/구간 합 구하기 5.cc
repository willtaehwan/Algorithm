#include <iostream>

using namespace std;

int N, M;

int map[1030][1030] = { 0, };

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <=N; i++) {
		int col_result = 0;
		for (int j = 1; j <=N; j++) {
			int col;
			cin >> col;
			col_result += col;
			map[i][j] = col_result + map[i-1][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << map[x2][y2] - map[x1 - 1][y2] - map[x2][y1 - 1] + map[x1 - 1][y1 - 1]<<'\n';
	}



	return 0;
}