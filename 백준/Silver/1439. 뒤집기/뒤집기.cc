#include <iostream>

using namespace std;

int main() {

	string row;
	cin >> row;
	char check = row[0];
	int sum = 1;
	for (int i = 1; i < row.size(); i++) {
		if (row[i] != check) {
			sum++;
			check = row[i];
		}
	}

	cout << sum / 2;

	return 0;
}