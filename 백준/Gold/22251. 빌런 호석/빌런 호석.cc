#include <iostream>

using namespace std;

int N, K, P, X;

int map[10][10] = { 0, };

int orign[7] = { 0, };
int rep[7] = { 0, };

int num[10] = {
		0b1111110,
		0b0110000,
		0b1101101,
		0b1111001,
		0b0110011,
		0b1011011,
		0b1011111,
		0b1110000,
		0b1111111,
		0b1111011
};

void ch(int n, int* arr) {
	int cnt = 0;

	for (int i = 0; i < K; i++) arr[i] = 0;

	while (n) {
		int temp = n % 10;
		arr[cnt++] = temp;
		n /= 10;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> P >> X;

	for (int i = 0; i < 10; i++) {
		for (int j = i+1; j < 10; j++) {
			int a = num[i] ^ num[j];
			int cnt = 0;
			for (int k = 0; k < 7; k++) {
				if (a & (1 << k)) cnt++;
			}
			map[i][j] = cnt;
			map[j][i] = cnt;
		}
	}
	
	ch(X, orign);

	int tot = 0;
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		ch(i, rep);
		int cnt = 0;
		bool flag = true;
		for (int k = 0; k < K; k++) {
			cnt += map[rep[k]][orign[k]];
			if (cnt > P) {
				flag = false;
				break;
			}
		}
		if (flag) tot++;
		
	}

	cout << tot;

	return 0;
}