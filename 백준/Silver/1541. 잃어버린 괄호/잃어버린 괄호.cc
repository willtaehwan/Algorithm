#include <iostream>

using namespace std;

char arr[101] = { 0, };

int main(){

	string row;
	cin >> row;

	// -3 : 빼기
	// -5 : 더하기

	int sum = 0;
	int temp = 0;
	int flag = 0;
	for (int i = 0; i <= row.length(); i++) {
		
		int nowNum = int(row[i] - '0');
		//cout << nowNum << " ";
		if (nowNum == -3) {
			//cout << temp << endl;
			if (flag == 0) {
				sum += temp;
				temp = 0;
				flag = 1;
			}
			else {
				sum -= temp;
				temp = 0;
			}
			continue;
		}

		if (nowNum == -5) {
			//cout << temp << endl;
			if (flag == 0) {
				sum += temp;
				temp = 0;
			}
			else {
				sum -= temp;
				temp = 0;
			}
			continue;
		}

		if (nowNum == -48) {
			if (flag == 0) {
				sum += temp;
			}
			else {
				sum -= temp;
			}
			continue;
		}

		temp = temp * 10 + nowNum;
		
	}
	//cout << endl;
	cout << sum;

	return 0;
}