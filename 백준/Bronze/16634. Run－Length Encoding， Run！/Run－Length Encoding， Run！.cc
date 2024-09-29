#include <iostream>

using namespace std;

int main() {
	char ty;
	string str;
	cin >>ty >> str;

	if (ty == 'E') {
		char prev = str[0];
		int cnt = 1;
		for (int i = 1; i < str.size(); i++) {
			char now = str[i];
			if (now == prev) {
				cnt++;
				continue;
			}
			else {
				cout << prev << cnt;
				cnt = 1;
				prev = now;
			}
		}
		cout << prev << cnt;
	}
	else {
		for (int i = 0; i < str.size(); i = i + 2) {

			int len = str[i + 1] - '0';

			for (int j = 0; j< len; j++) {
				cout << str[i];
			}
		}
	}
	

	return 0;
}