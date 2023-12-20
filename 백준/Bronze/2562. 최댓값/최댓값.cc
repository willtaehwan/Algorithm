#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int maxNum = 0;
	int maxCnt = 0;

	for (int i = 1; i <= 9; i++) {
		int a = 0;
		cin >> a;
		if (maxNum < a) {
			maxNum = a;
			maxCnt = i;
		}
	}

	cout << maxNum << '\n';
	cout << maxCnt;

	return 0;
}