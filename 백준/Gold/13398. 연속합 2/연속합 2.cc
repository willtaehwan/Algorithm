#include <iostream>

using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	int max_result = -1010;
	int prev1 = -1010;
	int prev2 = -1010;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		max_result = max(max_result, a);

		prev2 = max(prev1, prev2 + a);
		prev1 = max(prev1 + a, a);

		max_result = max(max_result, max(prev1, prev2));
	}

	cout << max_result;

	return 0;
}