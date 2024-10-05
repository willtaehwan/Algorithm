#include <iostream>

using namespace std;

string str;

int map[3][3] = { 0, };

bool str_ch() {
	int ocnt = 0;
	int xcnt = 0;

	int flag = true;
	for (int i = 0; i < 9; i++) {
		if (str[i] == 'O') {
			ocnt++;
			map[i / 3][i % 3] = 1;
		}
		if (str[i] == 'X') {
			xcnt++;
			map[i / 3][i % 3] = -1;
		}
		if (str[i] == '.') {
			map[i / 3][i % 3] = 0;
			flag = false;
		}
	}
	if (ocnt > xcnt || ocnt < xcnt - 1) return false;

	int rb = 0;
	int cb = 0;
	int dcnt1 = 0;
	int dcnt2 = 0;

	for (int i = 0; i < 3; i++) {
		int rcnt = 0;
		int ccnt = 0;
		dcnt1 += map[i][i];
		dcnt2 += map[2 - i][i];
		for (int j = 0; j < 3; j++) {
			rcnt += map[i][j];
			ccnt += map[j][i];
		}
		if (rcnt == 3 || rcnt == -3) rb++;
		if (ccnt == 3 || ccnt == -3) cb++;
		if (xcnt > ocnt) {
			if (rcnt == 3 || ccnt == 3) return false;
			if (dcnt1 == 3 || dcnt2 == 3) return false;
			if (dcnt1 == -3 || dcnt2 == -3) return true;
		}
		if (xcnt == ocnt) {
			if (rcnt == -3 || ccnt == -3) return false;
			if (dcnt1 == -3 || dcnt2 == -3) return false;
			if (dcnt1 == 3 || dcnt2 == 3) return true;
		}
	}

	if (rb > 1 || cb > 1) return false;

	if (rb == 0 && cb == 0 && !flag) return false;

	return true;
}

int main() {

	while (1) {
		cin >> str;
		if (str == "end") break;
		/*for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << str[i*3+j] << " ";
			}
			cout << '\n';
		}*/
		bool flag = str_ch();
		
		if (flag) cout << "valid\n";
		else cout << "invalid\n";
	}


	return 0;
}