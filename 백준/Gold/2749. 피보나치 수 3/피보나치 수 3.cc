#include <iostream>
#define ll long long
using namespace std;

ll N;

int main() {
	cin >> N;

	N %= 1500000;

	int cur = 1, prev = 0, temp = 0;

	for (int i = 0; i < N - 1; i++) {
		temp = (cur + prev) % 1000000;
		prev = cur;
		cur = temp;
	}
	if (N == 0) cur = 0;
	if (N == 1) cur = 1;
	cout << cur;

	return 0;
}