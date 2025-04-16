#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int w;
	long long v;

	bool operator<(Node right) const {
		if (w < right.w) return true;
		return false;
	}
};

int N, K;
vector<Node> v;
vector<int> b;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	for (int i = 0; i < K; i++) {
		int a;
		cin >> a;
		b.push_back(a);
	}

	sort(v.begin(), v.end());
	sort(b.begin(), b.end());

	long long ans = 0;

	priority_queue<int> pq;
	int idx = 0;

	for (int i = 0; i < b.size(); i++) {
		int now = b[i];

		while (idx < v.size() && v[idx].w <= now) {
			pq.push(v[idx].v);
			idx++;
		}

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}

	cout << ans;

	return 0;
}
