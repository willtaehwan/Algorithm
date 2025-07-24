#include <iostream>
using namespace std;

int N, Q;

int arr[5005][5005] = { 0, };

int bi_search(int row, int col) {

	int l = 0;
	int r = 5000;

	while (l < r) {
		int mid = (l + r) / 2;

		int br = (row - mid) < 1 ? 1 : (row - mid);
		int bc = (col - mid) < 1 ? 1 : (col - mid);
		int tr = (row + mid) > 5000 ? 5001 : (row + mid);
		int tc = (col + mid) > 5000 ? 5001 : (col + mid);

		int now = arr[tr][tc] - arr[br - 1][tc] - arr[tr][bc - 1] + arr[br - 1][bc - 1];

		if (now > 0) r = mid;
		else l = mid + 1;
	}

	return l;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> Q;

	int mr = 0;
	int mc = 0;
	for (int i = 0; i < N; i++) {
		int r, c;
		cin >> r >> c;
		arr[r+1][c+1] = 1;
		mr = max(mr, r+1);
		mc = max(mc, c+1);
	}

	for (int i = 1; i <= 5001; i++) {
		for (int j = 1; j <= 5001; j++) {
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}

	for (int i = 0; i < Q; i++) {
		int r, c;
		cin >> r >> c;
		cout << bi_search(r + 1, c + 1)<<'\n';
	}

	return 0;
}