#include <iostream>
#include <vector>

using namespace std;

int N;

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
			if (map[type][i][j] == 1) sum++;
		}

		//cout << " i : " << i << ", sum :" << sum << endl;
		if (sum == 4) {
			flag = i;
			point++;
		}

		if (i < 2 && sum > 0) flag = i;
	}

	//cout << "flag = " << flag << endl;
	if (flag >= 2) {
		for (int i = flag - 1; i >= 0; i--) {
			for (int j = 0; j < 4; j++) {
				map[type][i + 1][j] = map[type][i][j];
			}
		}
		stackMap(type);
	}
	else if (flag == 1) {
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

void block(int t, int row, int col, int type) {
	vector<int> v;

	v.push_back(col);
	if (t == 2) {
		if (type == 0) v.push_back(col + 1);
		else v.push_back(col - 1);
	}

	Node site = { 5,v[0] };

	for (int i = 2; i < 6; i++) {
		if ((t == 2 && map[type][i][v[1]] == 1) || map[type][i][v[0]] == 1) {
			site = { i - 1, v[0] };
			break;
		}
	}
	//cout << site.row << " " << site.col << endl;

	map[type][site.row][site.col] = 1;
	if (t == 2) map[type][site.row][v[1]] = 1;
	if (t == 3) map[type][site.row - 1][site.col] = 1;

	stackMap(type);

	return;
}

int main() {

	cin >> N;

	int lastsum = 0;

	for (int i = 0; i < N; i++) {
		int t, row, col, t2, row2, col2;
		cin >> t >> row >> col;
		col2 = 3 - row;
		if (t == 1) {
			row2 = col;
			t2 = 1;
		}
		else if (t == 2) {
			row2 = col;
			t2 = 3;
		}
		else {
			row2 = col - 1;
			t2 = 2;
		}

		block(t, row, col, 0);
		block(t2, row2, col2, 1);
		int sum = 0;
		for (int tp = 0; tp < 2; tp++) {
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 4; j++) {
					//cout << gmap[i][j] << " ";
					if (map[tp][i][j] == 1) sum++;
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

	cout << point << endl;
	cout << lastsum;

	return 0;
}