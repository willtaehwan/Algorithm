#include <iostream>
#include <vector>
using namespace std;

string str;
int DP[2501] = { 0, };
bool ch[2501] = { 0, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	
	DP[0] = 0;
	for (int i = 1; i <= str.size(); i++) {

		DP[i] = DP[i - 1] + 1;
		for (int j = 1; j <= i; j++) {
			if (str[i - 1] == str[j - 1] && (i - j <= 1 || ch[j + 1])) {
				ch[j] = true;
				DP[i] = min(DP[i], DP[j - 1] + 1);
			}
			else ch[j] = false;
		}
	}

	cout << DP[str.size()];

	return 0;
}