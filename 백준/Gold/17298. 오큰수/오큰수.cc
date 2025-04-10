#include <iostream>
#include <stack>
using namespace std;

struct Node {
	int idx;
	int val;
};

int N;

int arr[1000010] = { 0, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	stack<Node> s;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr[i] = -1;

		while (!s.empty()) {
			Node now = s.top();

			if (now.val < a) {
				arr[now.idx] = a;
				s.pop();
			}
			else break;
		}

		s.push({ i,a });
		
	}

	for (int i = 0; i < N; i++) cout << arr[i] << " ";

	return 0;
}