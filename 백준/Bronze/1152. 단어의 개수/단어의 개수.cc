#include <iostream>
#include <string>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string row;
	getline(cin, row);

	int cnt = 1;
	int last = row.size();

	if (last == 1 && row[0] == ' ') {
		cout << 0;
		return 0;
	}

	int i = 0;
	if (row[0] == ' ') i++;
	if (row[last - 1] == ' ') last--;
	for (; i < last; i++) {
		if (row[i] == ' ') cnt++;
	}

	cout << cnt;
	return 0;
}