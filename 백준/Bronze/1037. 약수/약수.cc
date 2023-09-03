#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

	int N;
	int A[51];
	cin >> N;


	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	sort(A, A + N);
	//cout << A[0] << " " << A[N - 1];
	cout << A[0] * A[N - 1];
	return 0;
}