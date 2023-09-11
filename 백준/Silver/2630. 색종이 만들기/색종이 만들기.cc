#include <iostream>

using namespace std;

int map[130][130] = { 0, };
int N;
int white = 0;
int blue = 0;
void checkRect(int row, int col, int now) {

	int check = map[row][col];

	if (now == 1) {
		//cout << "check = " << check << "   row : " << row << "   col : " << col << "  now : " << now << endl;
		if (check == 1) {
			blue++;
		}
		else {
			white++;
		}
		return;
	}

	
	int flag = 0;
	for (int i = row; i < row+now; i++) {
		
		if (flag == 1) break;

		for (int j = col; j < col + now; j++) {
			if (map[i][j] != check) {
				flag = 1;
				checkRect(row, col, now / 2);
				checkRect(row + now / 2, col, now / 2);
				checkRect(row, col + now / 2, now / 2);
				checkRect(row + now / 2, col + now / 2, now / 2);
				break;
			}
		}
	}

	if (flag == 0) {
		//cout << "check = " << check << "   row : " << row << "   col : " << col << "  now : " << now << endl;
		if (check == 1) {
			blue++;
		}
		else {
			white++;
		}
	}

}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	checkRect(0,0,N);

	cout << white << endl;
	cout << blue;

	return 0;
}