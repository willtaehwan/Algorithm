#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int row;
	int col;
};

int N, Q;
int mr = 0;
int mc = 0;
int arr[5005][5005] = { 0, };

vector<Node> v;

int bi_search(int row, int col) {

	int l = 0;
	int r = max(mr, mc);

	while (l < r) {
		int mid = (l + r) / 2;

		int br = (row - mid) < 1 ? 1 : (row - mid);
		int bc = (col - mid) < 1 ? 1 : (col - mid);
		int tr = (row + mid) > mr ? mr : (row + mid);
		int tc = (col + mid) > mc ? mc : (col + mid);

		int now = arr[tr][tc] - arr[br - 1][tc] - arr[tr][bc - 1] + arr[br - 1][bc - 1];

		if (now > 0) r = mid;
		else l = mid + 1;
	}

	return l;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> Q;


	for (int i = 0; i < N; i++) {
		int r, c;
		cin >> r >> c;
		arr[r+1][c+1] = 1;
		mr = max(mr, r+1);
		mc = max(mc, c+1);
	}

	for (int i = 0; i < Q; i++) {
		int r, c;
		cin >> r >> c;
		v.push_back({ r + 1, c + 1 });
		mr = max(mr, r + 1);
		mc = max(mc, c + 1);
	}

	for (int i = 1; i <= mr; i++) {
		for (int j = 1; j <= mc; j++) {
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}

	for (int i = 0; i < v.size(); i++) {
		cout << bi_search(v[i].row, v[i].col) << '\n';
	}

	return 0;
}