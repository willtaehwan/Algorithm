#include <iostream>
#include <algorithm>
using namespace std;

int N;

int lope[100001] = { 0, };

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> lope[i];
	}

	// case 1 : 가장 작은 값 x N
	// case 2 : 가장 큰 값
	// case 3 : 일부만 씀  Ex. 1 20 25 30 -> 25
	//  -> 작은 값 부터 하나씩 없애 가며 case 1 계산
	
	sort(lope, lope + N);
	
	int maxWeight = 0;
	for (int i = 0; i < N; i++) {
		int result = lope[i] * (N - i);
		if (result > maxWeight) {
			maxWeight = result;
		}
	}

	cout << maxWeight;

	return 0;
}