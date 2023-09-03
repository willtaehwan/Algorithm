#include <iostream>

using namespace std;



long long int f[1000001] = { 0, };


int main() {

	int N;

	int Testcase;

	cin >> Testcase;

	for (int i = 1; i <= 1000001; i++) {
		for (int j = i; j <= 1000001; j+=i){
			f[j] += i;
		}
	}

	for (int i = 2; i <= 1000001; i++) {
		f[i] += f[i - 1];
	}


	for (int i = 0; i < Testcase; i++) {

		scanf("%d", &N);
		printf("%lld\n", f[N]);
	}

	return 0;
}