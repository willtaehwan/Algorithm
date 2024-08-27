#include <iostream>

using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

bool cal_bit(int k) {
	while (k > 1) {
		if(k % 2 == 1) return false;
		k = k >> 1;
	}
	return true;
}

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int G = gcd(A, gcd(B, C));
	int sum = (A + B + C) / G;

	cout << (sum % 3 == 0 && cal_bit(sum / 3));

	return 0;
}