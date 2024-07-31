#include <iostream>

using namespace std;

string str;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str;

	int rem = 0;
	for (int i = 0; i < str.size(); i++) {
		rem = (rem * 10 + (str[i] - '0')) % 20000303;
	}
	cout << rem;

	return 0;
}