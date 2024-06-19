#include <iostream>

using namespace std;

// 남 : 받은 번호 배수 변경
// 여 : 받은 번호 기준 대칭되는 모든 구간 변경

int S, N;
bool swit[101];

int main() {

	cin >> S;
	for (int i = 0; i < S; i++) {
		cin >> swit[i];
	}

	cin >> N;
	for (int i = 0; i < N; i++) {
		int g, n;
		cin >> g >> n;
		n -= 1;

		if (g == 1) {
			for (int i = n; i < S; i += n+1) {
				swit[i] = !swit[i];
			}
		}
		else {
			int c = 1;
			swit[n] = !swit[n];
			while (1) {
				if (n - c < 0 || n + c >= S) break;

				if (swit[n + c] == swit[n - c]) {
					swit[n + c] = !swit[n + c];
					swit[n - c] = !swit[n - c];
					c++;
				}
				else break;
			}
		}

	}


	for (int i = 0; i < S; i++) {
		if (i % 20 == 0 && i != 0) cout << "\n";
		cout << swit[i] << " ";
	}

	return 0;
}