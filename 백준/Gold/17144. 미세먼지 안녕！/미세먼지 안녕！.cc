#include <iostream>

using namespace std;

int R, C, T;

int map[51][51] = { 0, };

struct Node {
	int row;
	int col;
};

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

void goDust() {

	int temp[51][51] = { 0, };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			
			if (map[i][j] == 0) continue;
			if (map[i][j] == -1) {
				temp[i][j] = -1;
				continue;
			}
			int flood = map[i][j] / 5;

			int cnt = 0;
			for (int d = 0; d < 4; d++) {
				int ner = i + dr[d];
				int nec = j + dc[d];

				if (ner < 0 || nec < 0 || ner >= R || nec >= C) continue;
				if (map[ner][nec] == -1) continue;
				temp[ner][nec] += flood;
				cnt++;
			}

			temp[i][j] += (map[i][j] - flood * cnt);

		}
	}

	for(int i = 0; i<R;i++){
		for (int j = 0; j < C; j++) {

			

			map[i][j] = temp[i][j];
		}
	}

	return;
}

void goWindUp(int stRow, int stCol) {

	int d = 0;
	int ner = stRow-1;
	int nec = stCol;

	while (1) {
		Node now = { ner, nec };
		
		ner += dr[d];
		nec += dc[d];
		//cout << ner << " " << nec << endl;
		map[now.row][now.col] = map[ner][nec];

		if (ner + dr[d] < 0) d = 3;
		if (nec + dc[d] >= C) d = 1;
		if (ner + dr[d] >= stRow + 1) d = 2;
		if (nec + dc[d] == stCol && ner + dr[d] == stRow) {
			map[ner][nec] = 0;
			break;
		}
	}
	
	return;
}

void goWindDown(int stRow, int stCol) {

	int d = 1;
	int ner = stRow+1;
	int nec = stCol;

	while (1) {
		Node now = { ner, nec };

		ner += dr[d];
		nec += dc[d];
		//cout << ner << " " << nec << endl;
		map[now.row][now.col] = map[ner][nec];

		if (ner + dr[d] >= R) d = 3;
		if (nec + dc[d] >= C) d = 0;
		if (ner + dr[d] <= stRow - 1) d = 2;
		if (nec + dc[d] == stCol && ner + dr[d] == stRow) {
			map[ner][nec] = 0;
			break;
		}
	}


	return;

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> T;
	
	int stRow;
	int stCol;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				stRow = i;
				stCol = j;
			}
		}
	}

	for(int k = 0; k<T;k++){
		goDust();
		goWindUp(stRow-1, stCol);
		//cout << endl;
		goWindDown(stRow, stCol);
	}

	//cout << endl;

	int result = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			result += map[i][j];
			//cout << map[i][j] << " ";
		}
		//cout << endl;
	}

	cout << result+2;

	return 0;
}