#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int N, M, H;

int DP[52][1010] = { 0, };
int arr[52][11] = { 0, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> H;

	string st;
	getline(cin, st);

	for (int i = 1; i <= N; i++) {
		string str;
		getline(cin, str);

		stringstream sstr(str);
		int num;
		int cnt = 1;
		while (sstr >> num) {
			arr[i][cnt++] = num;
		}
		for (int j = cnt; j <= M; j++) arr[i][j] = -1;
	}

	DP[0][0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			int nb = arr[i][j];
			if (nb == -1) break;
			for (int k = 0; k <= H; k++) {
				if (k + nb > H) break;
				DP[i][k + nb] = (DP[i][k + nb] + DP[i - 1][k]) % 10007;
			}
		}
	}

	cout << DP[N][H];

	return 0;
}