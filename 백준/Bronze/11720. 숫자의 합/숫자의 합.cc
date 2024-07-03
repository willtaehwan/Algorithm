#include <iostream>

using namespace std;

int main() {

	string str;
	int N;

	cin >> N;
	cin >> str;
	int sum = 0;
	for (int i = 0; i < str.size(); i++) sum += (int)(str[i] - '0');

	cout << sum;

	return 0;
}