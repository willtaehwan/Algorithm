#include <iostream>

using namespace std;

int A[3], B[3];

int reverse(int a) {

	int temp = 0;
	for (int i = 0; i < 3; i++) {
		int now = a % 10;
		temp = temp * 10 + now;
		a /= 10;
	}

	return temp;
}

int main() {

	int a, b;
	cin >> a >> b;
	
	int A = reverse(a);
	int B = reverse(b);
	
	if (A > B) cout << A;
	else cout << B;

	return 0;
}