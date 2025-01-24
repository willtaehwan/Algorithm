#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int idx;
	int size;

	bool operator<(Node right) const{
		if (size < right.size) return true;
		else return false;
	}

};

int M, N;

vector<Node> v[101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			v[i].push_back({ j,a });
		}
		sort(v[i].begin(), v[i].end());
		for (int j = 1; j < N; j++) {
			if (v[i][j - 1].size == v[i][j].size) v[i][j].idx = v[i][j - 1].idx;
		}
	}

	
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		for (int j = i + 1; j < M; j++) {
			bool flag = true;
			for (int k = 0; k < N; k++) {
				if (v[i][k].idx != v[j][k].idx) {
					flag = false;
					break;
				}
			}
			if (flag) cnt++;
		}
	}

	cout << cnt;

	return 0;
}