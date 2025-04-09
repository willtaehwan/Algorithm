#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int idx;
	int val;

	bool operator<(Node right) const {
		if (val > right.val) return true;
		if (val < right.val) return false;

		if (idx > right.idx) return true;
		return false;
	}

};

int N, L;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;

	priority_queue<Node> pq;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		pq.push({ i, a });

		while (1) {
			Node now = pq.top();

			if (now.idx <= i - L) pq.pop();
			else {
				cout << now.val << " ";
				break;
			}
		}
	}


	return 0;
}