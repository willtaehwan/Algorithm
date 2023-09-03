#include <iostream>

using namespace std;

int g[1000001] = { 0, };

int main() {

	int N;
	g[0] = 1;
	g[1] = 1;
	

	for (int i = 2; i < 1000001; i++) {

		if (g[i] != 0) {
			continue;
		}

		for (int j = i*2; j < 1000001; j += i) {
			g[j] = 1;
		}
	}

	g[2] = 1;

	while (scanf("%d", &N)) {

		if (N == 0) {
			break;
		}

		int a, b;
		int flag = 0;
		for (int i = 3; i < N; i++) {
			if (g[i] != 0) {
				continue;
			}

			

			if (g[N - i] == 0) {
				a = i;
				b = N - i;
				flag = 1;
				break;
			}

		}

		if (flag == 1) {
			printf("%d = %d + %d\n", N, a, b);
		}
		else {
			printf("Goldbach's conjecture is wrong.");
		}

	}


	return 0;
}