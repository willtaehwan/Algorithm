#include<iostream>
#include<algorithm>
#define MOD_NUM 1000000007;
using namespace std;

int DP[101][101][101] = { 0, };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, L, R;
    cin >> N >> L >> R;

    DP[1][1][1] = 1;

    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= min(L,i); ++j) {
            for (int k = 1; k <= min(R,i); ++k) {
                DP[i][j][k] = (DP[i - 1][j - 1][k] + DP[i - 1][j][k - 1] + (long long)DP[i - 1][j][k] * (i - 2)) % MOD_NUM;
            }
        }
    }

    cout << DP[N][L][R];

    return 0;
}