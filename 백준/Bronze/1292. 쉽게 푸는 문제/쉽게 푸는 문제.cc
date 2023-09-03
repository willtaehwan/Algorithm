#include <iostream>
using namespace std;

int DAT[1001] = { 0, };

int main() {

	int A, B;

	cin >> A >> B;
	int cnt = 1;
	int ccnt = 1;
	int input_num = 1;
	for (int i = 1; i < 1001; i++) {
		DAT[i] = input_num;
		if (ccnt == cnt) {
			ccnt++;
			input_num++;
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	int result = 0;
	for (int i = A; i <= B; i++) {
		result += DAT[i];
	}

	cout << result;

	return 0;
}