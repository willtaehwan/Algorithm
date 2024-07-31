#include <iostream>
#define MOD 20000303
using namespace std;

string str;

int main() {
	
	cin >> str;

	int rem = 0;
	for (int i = 0; i < str.size(); i++) {
		rem = (rem * 10 + (str[i] - '0')) % MOD;
	}
	cout << rem;

	return 0;
}