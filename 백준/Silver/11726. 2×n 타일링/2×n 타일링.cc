#include <iostream>

using namespace std;

long long int DP[1001] = { 0, };

int main() {

	int N;

	cin >> N;

	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= N; i++) {
		DP[i] = (DP[i - 1] + DP[i - 2])%10007;
		//cout << DP[i]<<endl;
	}
	int ans = DP[N];
	
	cout << ans;

	return 0;
}