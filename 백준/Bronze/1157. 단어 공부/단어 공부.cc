#include <iostream>

using namespace std;

int DAT[26] = { 0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string row;
	cin >> row;
	
	for (int i = 0; i < row.size(); i++) {
		int ans = 0;
		if (row[i] < 91) ans = int(row[i] - 'A');
		else ans = int(row[i] - 'a');
		DAT[ans]++;
	}
	int maxSum = 0;
	int maxChar = 0;
	int flag = 0;
	for (int i = 0; i < 26; i++) {
		if (maxSum < DAT[i]) {
			maxSum = DAT[i];
			maxChar = i;
			flag = 1;
			continue;
		}
		
		if (maxSum == DAT[i] && maxSum != 0) {
			flag = 2;
		}
	}

	if (flag == 1) cout << char('A' + maxChar);
	else cout << "?";

	return 0;
}