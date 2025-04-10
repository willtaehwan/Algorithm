#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int idx;
	int val;

	bool operator<(Node right) const {
		if (val > right.val) return true;
		return false;
	}
};

int N;

int arr[1000010] = { 0, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	priority_queue<Node> q;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr[i] = -1;

		while (!q.empty()) {
			Node now = q.top(); 

			if (now.val < a) {
				arr[now.idx] = a;
				q.pop();
			}
			else break;
		}

		q.push({ i,a });
	}

	for (int i = 0; i < N; i++) cout << arr[i] << " ";

	return 0;
}