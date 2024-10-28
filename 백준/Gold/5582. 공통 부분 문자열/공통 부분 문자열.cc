#include <iostream>

using namespace std;

int DP[2][4002] = { 0, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str1, str2;
	cin >> str1 >> str2;
	int res = 0;
	for (int i = 0; i < str1.size(); i++) {
		int n = i % 2;
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i] == str2[j - 1]) DP[n][j] = DP[!n][j - 1] + 1;
			else DP[n][j] = 0;

			if (DP[n][j] > res) res = DP[n][j];
		}
	}
	cout << res;

	return 0;
}