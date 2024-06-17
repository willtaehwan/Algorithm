#include <iostream>

using namespace std;

string str;

bool is_vo(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {

	while (1) {
		bool flag = true, abm_cnt = false;
		int m_cnt = 0, j_cnt = 0;
		cin >> str;
		if (str == "end") break;
		for (int i = 0; i < str.size(); i++) {
			if (is_vo(str[i])) {
				j_cnt = 0;
				m_cnt++;
				abm_cnt = true;
			}
			else {
				m_cnt = 0;
				j_cnt++;
			}

			if (i != 0 && str[i] == str[i - 1]) {
				if (str[i] == 'e' || str[i] == 'o') continue;
				else flag = false;
			}

			if (m_cnt == 3 || j_cnt == 3) flag = false;
		}

		if (flag && abm_cnt) cout << "<" << str << "> is acceptable.\n";
		else cout << "<" << str << "> is not acceptable.\n";
	}

	return 0;
}