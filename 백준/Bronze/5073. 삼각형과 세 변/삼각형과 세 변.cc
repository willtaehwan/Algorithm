#include <iostream>

using namespace std;


int main() {

	int a, b, c;
	
	while(1){
	
		cin >> a >> b >> c;

		int sum = a + b + c;
		if (sum == 0) break;

		if (a + b <= c || a + c <= b || b + c <= a) {
			cout << "Invalid\n";
			continue;
		}

		if (a == b && b == c) cout << "Equilateral";
		else if (a == b || b == c || a == c) cout << "Isosceles";
		else cout << "Scalene";

		cout << '\n';
	}

	return 0;
}