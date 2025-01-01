#include <iostream>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	int z_cnt = 0;
	int o_cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '0')z_cnt++;
		else o_cnt++;
	}

	z_cnt /= 2;
	o_cnt /= 2;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '1') {
			if (o_cnt > 0) o_cnt--;
			else cout << 1;
		}
		else {
			if (z_cnt > 0) {
				cout << 0;
				z_cnt--;
			}
		}
	}


	return 0;
}