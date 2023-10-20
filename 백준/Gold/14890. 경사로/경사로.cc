#include <iostream>

using namespace std;

int N, L;

int map[101][101] = { 0, };

int routeCheck_row(int row) {
	int flag = 0;
	int nowFloor = map[row][0];
	int cnt = 1;
	for (int i = 1; i < N; i++) {

		if (flag == 1) {
			if (map[row][i] != nowFloor) {
				return 0;
			}
			else {
				cnt++;
				if (cnt == L) {
					flag = 0;
					cnt = 0;
					continue;
				}
				continue;
			}
		}

		if (map[row][i] == nowFloor) {
			cnt++;
			continue;
		}

		if (map[row][i] > nowFloor + 1 || map[row][i] < nowFloor - 1) {
			return 0;
		}

		if (map[row][i] == nowFloor + 1) {
			if (cnt >= L) {
				cnt = 1;
				nowFloor = map[row][i];
				continue;
			}
			else {
				return 0;
			}
		}

		if (map[row][i] == nowFloor - 1) {
			nowFloor = map[row][i];
			cnt = 1;
			if (cnt == L) {
				flag = 0;
				if (map[row][i + 1] > nowFloor) return 0;
			}
			else flag = 1;

		}

	}

	if (flag == 0) return 1;
	if (flag == 1) return 0;

}

int routeCheck_col(int col) {
	int flag = 0;
	int nowFloor = map[0][col];
	int cnt = 1;
	for (int i = 1; i < N; i++) {

		if (flag == 1) {
			if (map[i][col] != nowFloor) {
				return 0;
			}
			else {
				cnt++;
				if (cnt == L) {
					flag = 0;
					cnt = 0;
					continue;
				}
				continue;
			}
		}

		if (map[i][col] == nowFloor) {
			cnt++;
			continue;
		}

		if (map[i][col] > nowFloor + 1 || map[i][col] < nowFloor - 1) {
			return 0;
		}

		if (map[i][col] == nowFloor + 1) {
			if (cnt >= L) {
				cnt = 1;
				nowFloor = map[i][col];
				continue;
			}
			else {
				return 0;
			}
		}

		if (map[i][col] == nowFloor - 1) {
			nowFloor = map[i][col];
			cnt = 1;
			if (cnt == L) {
				flag = 0;
				if (map[i+1][col] > nowFloor) return 0;
			}
			else flag = 1;
			
		}

	}

	if (flag == 0) return 1;
	if (flag == 1) return 0;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int result = 0;
	for (int i = 0; i < N; i++) {
		
		int rowR = routeCheck_row(i);
		int colR = routeCheck_col(i);
		//cout << i << " " << rowR << " " << colR << endl;

		result = result + rowR + colR;
	}

	cout << result;

	return 0;
}