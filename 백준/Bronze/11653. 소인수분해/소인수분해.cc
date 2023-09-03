#include <iostream>
using namespace std;

int flag = 0;

void func(int N) {

	if (N == 1) {
		flag = 1;
		return;
	}

	for (int i = 2; i <= N; i++) {

		if (flag == 1) {
			break;
		}

		if (N % i == 0) {
			cout << i << endl;
			func(N / i);
		}
	}
	
	

}

int main() {

	int N;

	cin >> N;

	func(N);
	

	return 0;
}