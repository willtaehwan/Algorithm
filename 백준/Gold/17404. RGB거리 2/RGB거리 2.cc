#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int N;

int arr[1001][3];
int rgb[1001][3];

int DP(int row, int col, int st) {

	if (row == N - 1) {
		if (col == st) return 1e9;
		else return rgb[row][col];
	}
	
	if (arr[row][col] != -1) return arr[row][col];

	arr[row][col] = min(DP(row + 1, (col + 1) % 3, st), DP(row + 1, (col + 2) % 3, st)) + rgb[row][col];
	return arr[row][col];
}

int check(int color) {

	for (int i = 0; i < N; i++) fill_n(arr[i], size(arr[i]), -1);

	return DP(0, color, color);

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		rgb[i][0] = r; rgb[i][1] = g; rgb[i][2] = b;
	}

	
	cout << min({ check(0), check(1), check(2) });

	return 0;
}