#include <iostream>

using namespace std;

int DP[4002][4002] = { 0, };

int main() {

	string str1, str2;
	cin >> str1 >> str2;
	int res = 0;
	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
			if (DP[i][j] > res) res = DP[i][j];
		}
	}
	cout << res;

	return 0;
}