#include <iostream>

using namespace std;

int H, W, N, M;

int calc() {

	int row = H / (N + 1);
	int col = W / (M + 1);
	if (H % (N + 1) != 0) row++;
	if (W % (M + 1) != 0) col++;

	return row * col;
}

int main() {

	cin >> H >> W >> N >> M;
	cout << calc();

	return 0;
}