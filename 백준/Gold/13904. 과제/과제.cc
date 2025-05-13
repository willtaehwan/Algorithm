#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int dl;
	int sc;

	bool operator<(Node r) const {
		if (sc > r.sc) return true;
		return false;
	}
};

int N;
int ans = 0;
bool arr[1001] = { 0, };
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

	for (int i = 0; i < v.size(); i++) {
		for (int j = v[i].dl; j > 0; j--) {
			if (!arr[j]) {
				arr[j] = true;
				ans += v[i].sc;
				break;
			}
		}
	}

	cout << ans;

	return 0;
}