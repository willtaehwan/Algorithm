#include <iostream>
using namespace std;

int main() {

	int a, b;

	cin >> a >> b;

	int c, d;
	if (a <= b) {
		c = a;
		d = b;
	}
	else {
		c = b;
		d = a;
	}

	for (int i = d; i >=1; i--) {
		if (a % i == 0 && b % i == 0) {
			//min_result = i;
			cout << i << endl;
			break;
		}
	}
	
	if (c == 1) {
		cout << d;
	}
	else {
		for (int i = 1; i <= c; i++) {
			if ((d * i) % c == 0) {
				cout << d * i;
				break;
			}
		}
	}
	


	return 0;
}