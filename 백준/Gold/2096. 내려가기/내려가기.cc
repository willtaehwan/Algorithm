#include <iostream>
#include <algorithm>
using namespace std;

int N;

int min_s[2][3];
int max_s[2][3];

int main() {

	cin >> N;

	int a, b, c;
	cin >> a >> b >> c;
	min_s[0][0] = max_s[0][0] = a;
	min_s[0][1] = max_s[0][1] = b;
	min_s[0][2] = max_s[0][2] = c;

	int max_r = 0, min_r = 0;

	max_r = max({ max_s[0][0], max_s[0][1], max_s[0][2] });
	min_r = min({ min_s[0][0], min_s[0][1], min_s[0][2] });

	for (int i = 1; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		int now = i % 2;
		int next = (i + 1)% 2;
		
		min_s[now][0] = min(min_s[next][0], min_s[next][1]) + a;
		min_s[now][1] = min({ min_s[next][0], min_s[next][1], min_s[next][2] }) + b;
		min_s[now][2] = min(min_s[next][1], min_s[next][2]) + c;

		max_s[now][0] = max(max_s[next][0], max_s[next][1]) + a;
		max_s[now][1] = max({ max_s[next][0], max_s[next][1], max_s[next][2] }) + b;
		max_s[now][2] = max(max_s[next][1], max_s[next][2]) + c;
		
		if (i == N - 1) {
			max_r = max({ max_s[now][0], max_s[now][1], max_s[now][2] });
			min_r = min({ min_s[now][0], min_s[now][1], min_s[now][2] });
		}
	}

	cout << max_r << " " << min_r;


	return 0;
}