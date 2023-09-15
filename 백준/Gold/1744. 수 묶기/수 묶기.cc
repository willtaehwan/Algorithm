#include <iostream>
#include <algorithm>
using namespace std;

int N;

int arr[51] = { 0, };
int plusCnt = 0;
int flag = 0;
int minusCnt = 0;
int sum = 0;
int oneflag = 0;
bool cmp(int i, int j){
	return j < i;
}

int calc(int a, int b, int c) {

	
	for (int i = 1; i < plusCnt; i = i + 2) {
		sum += arr[i-1] * arr[i];
	}
	
	for (int i = N - 2; i >= N-minusCnt; i= i-2) {
		sum += arr[i] * arr[i + 1];
	}

	if (a == 1) {
		sum += arr[plusCnt-1];
	}

	if (b == 1) return sum;
	else {
		if (c == 1) {
			sum += arr[N - minusCnt];
			return sum;
		}
		else {
			return sum;
		}
	}

}

int main() {

	cin >> N;

	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] > 1) {
			plusCnt++;
		}
		else if (arr[i] == 1) {
			sum += 1;
		}
		else if (arr[i] == 0) {
			flag = 1;
		}
		else {
			minusCnt++;
		}
	}
	int plusflag = 0;
	int minusflag = 0;
	if (plusCnt % 2 != 0) plusflag = 1;
	if (minusCnt % 2 != 0) minusflag = 1;

	sort(arr, arr + N, cmp);

	/*for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}*/

	//cout <<endl<< plusflag << " " << flag << " " << minusflag << endl;

	cout << calc(plusflag, flag, minusflag);

	return 0;
}