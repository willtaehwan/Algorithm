#include <iostream>
#define ull unsigned long long
using namespace std;

ull A, B, C;

int main() {

	cin >> A >> B >> C;
	ull result = 1;
	while (B > 0) {
		if (B % 2 == 1) {
			result *= A;
			result %= C;
		}

		A *= A;
		A %= C;
		B /= 2;

	}
	cout << result;

	return 0;
}