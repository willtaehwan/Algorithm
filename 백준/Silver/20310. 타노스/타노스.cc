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

	for (int i = 0; i < z_cnt / 2; i++) cout << 0;
	for (int i = 0; i < o_cnt / 2; i++) cout << 1;

	return 0;
}