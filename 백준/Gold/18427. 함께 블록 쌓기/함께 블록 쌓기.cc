#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int N, M, H;

int DP[52][11][1010] = {0,};
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
		arr[i][0] = 0;
		int num;
		int cnt = 1;
		while (sstr >> num) {
			arr[i][cnt++] = num;
		}
		for (int j = cnt; j <= M; j++) arr[i][j] = -1;
	}

	/*for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}*/

	arr[0][1] = -1;
	DP[0][0][0] = 1;
	arr[N + 1][1] = -1;

	for (int i = 1; i <= N+1; i++) {
		for (int j = 0; j <= M; j++) {
			int nb = arr[i][j];
			if (nb == -1) break;
			for (int k = 0; k <= H; k++) {
				if (k + nb > H) continue;
				for (int l = 0; l <= M; l++) {
					if (arr[i - 1][l] == -1) break;
					DP[i][j][k + nb] = (DP[i][j][k + nb] + DP[i - 1][l][k]) % 10007;
				}
			}
		}
	}

	int ans = 0;
	//for (int i = 0; i <= M; i++) ans += (DP[N][i][H] % 10007);
	
	cout << DP[N+1][0][H];

	return 0;
}