#include <iostream>

using namespace std;

int N;

int dr[] = { -1,-1,-1,0,0,0,1,1,1 };
int dc[] = { -1,0,1,-1,0,1,-1,0,1 };
bool map[6562][6562] = { 0, };


void rec(int size, int row, int col, bool cent) {

	if (size == 1) {
		map[row][col] = cent;
		return;
	}

	for (int i = 0; i < 9; i++) {
		int ner = row + dr[i] * (size/3);
		int nec = col + dc[i] * (size/3);

		if (i == 4) rec(size/3, ner, nec, false);
		else rec(size/3, ner, nec, cent);
	}

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	rec(N, N / 2, N / 2, true);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j]) cout << '*';
			else cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}