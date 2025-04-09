#include <iostream>
#include <deque>
using namespace std;

struct Node {
	int idx;
	int val;
};

int N, L;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;

	deque<Node> dq;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		while (!dq.empty()) {
			if (dq.back().val > a) dq.pop_back();
			else break;
		}

		dq.push_back({ i,a });
		if (dq.front().idx <= i - L) dq.pop_front();
		cout << dq.front().val << " ";
	}

	return 0;
}