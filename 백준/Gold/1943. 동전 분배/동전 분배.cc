#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool DP[101][100001] = { 0, };

struct Node {
	int num;
	int cnt;

	bool operator<(Node right) const {
		if (num < right.num) return true;
		return false;
	}
};

int result() {
	int N;
	vector<Node> v;
	cin >> N;

	int tot = 0;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
		tot += a * b;
	}
	//cout << "Total = " << tot / 2 << "\n";

	if (tot % 2 != 0) return 0;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= tot / 2; j++) {
			if (j == 0) DP[i][j] = true;
			else DP[i][j] = false;
		}
	}

	sort(v.begin(), v.end());
	//cout << '\n';
	for (int i = 1; i <= N; i++) {
		Node now = v[i - 1];
		//cout << now.num<<" ";

		for (int k = 0; k <= tot / 2; k++) {
			if (DP[i - 1][k]) {
				DP[i][k] = true;
				for (int j = 1; j <= now.cnt; j++) DP[i][k + now.num * j] = true;
			}
			if (DP[i][tot / 2]) return 1;
		}
	}
	


	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	for (int i = 0; i < 3; i++) cout << result()<<'\n';

	return 0;
}