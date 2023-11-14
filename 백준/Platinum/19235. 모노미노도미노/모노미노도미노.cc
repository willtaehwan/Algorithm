#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[2][6][4] = { 0, };

int point = 0;

struct Node {
	int row;
	int col;
};

void stackMap(int type) {

	int flag = 0;
	for (int i = 5; i >= 1; i--) {
		if (flag != 0) break;
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			if (map[type][i][j] != 0) sum++;
		}

		//cout << " i : " << i << ", sum :" << sum << endl;
		if (sum == 4) {
			flag = i;
			point++;

			for (int i = 0; i < 4; i++) {
				if (map[type][flag][i] == 0) continue;
				if (map[type][flag][i] == map[type][flag + 1][i]) map[type][flag + 1][i] = 1;
				if (map[type][flag][i] == map[type][flag-1][i]) map[type][flag-1][i] = 1;
			}

			for (int k = 0; k < 4; k++) map[type][flag][k] = 0;
			int sum2 = 0;
			for (int k = 0; k < 4; k++) {
				if (map[type][flag - 1][k] != 0) sum2++;
			}

			if (sum2 == 4) {
				flag = i - 1;
				point++;

				for (int i = 0; i < 4; i++) {
					if (map[type][flag][i] == 0) continue;
					if (map[type][flag][i] == map[type][flag-1][i]) map[type][flag-1][i] = 1;
				}

				for (int t = 0; t < 4; t++) map[type][flag][t] = 0;
			}

		}

		if (i < 2 && sum > 0) flag = i;
	}

	//cout << "flag = " << flag << endl;
	if (flag >= 2) {

		int start = flag - 1;
		

		for (int i = start; i > 0; i--) {

			int dflag = 0;
			for (int j = 0; j < 4; j++) {

				if (dflag == 1) {
					dflag = 0;
					continue;
				}

				int end = i;
				int end2 = i;
				if (map[type][i][j] == 0) continue;
				else if (map[type][i][j] == 1) {
					for (int k = i+1; k <= 5; k++) {
						if (map[type][k][j] == 0) end=k;
						else break;
					}

					map[type][end][j] = 1;
					map[type][i][j] = 0;
				}
				else if (map[type][i][j] == map[type][i - 1][j]) {
					int ch = map[type][i][j];
					for (int k = i + 1; k <= 5; k++) {
						if (map[type][k][j] == 0) end = k;
						else break;
					}

					map[type][end][j] = ch;
					map[type][i][j] = 0;
					map[type][end-1][j] = ch;
					map[type][i - 1][j] = 0;
					
				}
				else {
					dflag = 1;

					for (int k = i + 1; k <= 5; k++) {
						if (map[type][k][j] == 0) end = k;
						else break;
					}
					for (int k = i + 1; k <= 5; k++) {
						if (map[type][k][j+1] == 0) end2 = k;
						else break;
					}

					int result = min(end, end2);

					map[type][result][j] = map[type][i][j];
					map[type][result][j + 1] = map[type][i][j + 1];

					map[type][i][j] = 0;
					map[type][i][j + 1] = 0;

				}
			}
		}


		stackMap(type);
	}
	else if (flag == 1) {
		
		for (int i = 0; i < 4; i++) {
			if (map[type][5][i] == 0) continue;
			if (map[type][5][i] == map[type][4][i]) map[type][4][i] = 1;
		}

		for (int i = 4; i >= 0; i--) {
			for (int j = 0; j < 4; j++) {
				map[type][i + 1][j] = map[type][i][j];
			}
		}

		for (int j = 0; j < 4; j++) map[type][0][j] = 0;




		stackMap(type);
	}

	return;
}

void block(int t, int row, int col, int type,int num) {
	vector<int> v;

	v.push_back(col);
	if (t == 2) {
		if (type == 0) v.push_back(col + 1);
		else v.push_back(col - 1);
	}

	Node site = { 5,v[0] };

	for (int i = 2; i < 6; i++) {
		if ((t == 2 && map[type][i][v[1]] != 0) || map[type][i][v[0]] != 0) {
			site = { i - 1, v[0] };
			break;
		}
	}
	//cout << site.row << " " << site.col << endl;

	map[type][site.row][site.col] = num;
	if (t == 2) map[type][site.row][v[1]] = num;
	if (t == 3) map[type][site.row - 1][site.col] = num;

	stackMap(type);

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;

	int lastsum = 0;
	int cnt = 2;
	for (int n = 0; n < N; n++) {
		int t, row, col, t2, row2, col2,num;
		cin >> t >> row >> col;
		col2 = 3 - row;
		if (t == 1) {
			row2 = col;
			t2 = 1;
			num = 1;
		}
		else if (t == 2) {
			row2 = col;
			t2 = 3;
			num = cnt++;
		}
		else {
			row2 = col - 1;
			t2 = 2;
			num = cnt++;
		}

		block(t, row, col, 0, num);
		block(t2, row2, col2, 1,num);
		int sum = 0;
		for (int tp = 0; tp < 2; tp++) {
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 4; j++) {
					//cout << map[tp][i][j] << "\t";
					if (map[tp][i][j] != 0) sum++;
				}
				//cout << endl;
			}
			//cout << endl;
		}

		//cout << endl;
		//cout << "point "<<point << endl;
		//cout << "sum "<<sum << endl;
		lastsum = sum;
	}

	cout << point << "\n";
	cout << lastsum;

	return 0;
}