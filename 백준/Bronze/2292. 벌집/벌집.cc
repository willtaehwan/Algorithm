#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;

	int sum = 1;
	int cnt = 1;
	while (1) {
		if (N <= sum) break;
		sum = sum + 6*cnt;
		cnt++;
	}
	cout << cnt;

	return 0;
}