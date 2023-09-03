#include <iostream>
using namespace std;

char map[51][51];

int N;

int max_result = 0;

void changeCandyRow(int row, int col) {

	char temp;
	temp = map[row][col+1];
	map[row][col + 1] = map[row][col];
	map[row][col] = temp;


	char rowColor = map[row][0];
	char col1Color = map[0][col];
	char col2Color = map[0][col + 1];

	int rowColcnt = 0;
	int col1Colcnt = 0;
	int col2Colcnt = 0;
	
	for (int i = 0; i < N; i++) {
		
		if (map[row][i] == rowColor) {
			rowColcnt++;
		}
		else {
			if (max_result < rowColcnt) {
				max_result = rowColcnt;
			}
			rowColor = map[row][i];
			rowColcnt = 1;
		}

		if (map[i][col] == col1Color) {
			col1Colcnt++;
		}
		else {
			if (max_result < col1Colcnt) {
				max_result = col1Colcnt;
			}
			col1Color = map[i][col];
			col1Colcnt = 1;
		}

		if (map[i][col+1] == col2Color) {
			col2Colcnt++;
		}
		else {
			if (max_result < col2Colcnt) {
				max_result = col2Colcnt;
			}
			col2Color = map[i][col+1];
			col2Colcnt = 1;
		}

	}

	if (max_result < rowColcnt) {
		max_result = rowColcnt;
	}
	if (max_result < col1Colcnt) {
		max_result = col1Colcnt;
	}
	if (max_result < col2Colcnt) {
		max_result = col2Colcnt;
	}


	temp = map[row][col + 1];
	map[row][col + 1] = map[row][col];
	map[row][col] = temp;

}

void changeCandyCol(int row, int col) {

	char temp;
	temp = map[row + 1][col];
	map[row + 1][col] = map[row][col];
	map[row][col] = temp;


	char colColor = map[0][col];
	char row1Color = map[row][0];
	char row2Color = map[row+1][0];

	int colColcnt = 0;
	int row1Colcnt = 0;
	int row2Colcnt = 0;

	for (int i = 0; i < N; i++) {

		if (map[i][col] == colColor) {
			colColcnt++;
		}
		else {
			if (max_result < colColcnt) {
				max_result = colColcnt;
			}
			colColor = map[i][col];
			colColcnt = 1;
		}

		if (map[row][i] == row1Color) {
			row1Colcnt++;
		}
		else {
			if (max_result < row1Colcnt) {
				max_result = row1Colcnt;
			}
			row1Color = map[row][i];
			row1Colcnt = 1;
		}

		if (map[row+1][i] == row2Color) {
			row2Colcnt++;
		}
		else {
			if (max_result < row2Colcnt) {
				max_result = row2Colcnt;
			}
			row2Color = map[row+1][i];
			row2Colcnt = 1;
		}

	}

	if (max_result < colColcnt) {
		max_result = colColcnt;
	}
	if (max_result < row1Colcnt) {
		max_result = row1Colcnt;
	}
	if (max_result < row2Colcnt) {
		max_result = row2Colcnt;
	}


	temp = map[row + 1][col];
	map[row + 1][col] = map[row][col];
	map[row][col] = temp;

}


int main() {

	

	cin >> N;

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < N; j++) {
			map[i][j] = row[j];
		}

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			changeCandyRow(i, j);
			
		}
	}

	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < N; j++) {
			changeCandyCol(i, j);
		}
	}

	cout << max_result;

	return 0;
}