#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int st;
	int ed;

	bool operator<(Node r) const {
		if (st < r.st) return true;
		return false;
	}
};

int N;
vector<Node> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());
	int ans = 0;
	int s = -1e9;
	int e = -1e9;
	for (int i = 0; i < N; i++) {
		Node now = v[i];
		
		if (now.st <= e && now.ed > e) e = now.ed;
		else if (now.st > e) {
			ans += e - s;
			s = now.st;
			e = now.ed;
		}
		if (i == N - 1) ans += e - s;
	}

	cout << ans;

	return 0;
}