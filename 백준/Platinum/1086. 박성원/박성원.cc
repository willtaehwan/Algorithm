#include <iostream>
#define ll long long
using namespace std;

int N, K;

int map[15][750];
ll DP[100][32768];

string str[15];

int max_length = 0;

int modulo(int idx) {

	int res = 0;
	for (int i = 0; i < str[idx].size(); i++) {
		res = (res * 10 + (str[idx][i] - '0')) % K;
	}
	return res;
}

ll dp(int mod, int stat, int now_len) {
	
	if (stat == (1 << N) - 1) return mod ? 0 : 1;

	if (DP[mod][stat] != -1) return DP[mod][stat];

	ll result = 0;
	for (int i = 0; i < N; i++) {
		if (stat & (1 << i)) continue;
		int next_st = stat + (1 << i);
		int next_mod = (mod + map[i][now_len]) % K;
		result += dp(next_mod ,next_st, now_len - str[i].size());
	}
	DP[mod][stat] = result;
	return DP[mod][stat];
}

ll gcd(ll a, ll b){
	return b ? gcd(b, (a % b)) : a;
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	ll q = 1;
	for (int i = 2; i <= N; i++) q *= i;

	for (int i = 0; i < N; i++) {
		cin >> str[i];
		max_length += str[i].size();
	}
	max_length--;
	
	cin >> K;

	for (int i = 0; i < N; i++) fill_n(map[i], size(map[i]), -1);
	for (int i = 0; i < K; i++) fill_n(DP[i], size(DP[i]), -1);

	for (int i = 0; i < N; i++) {
		int s = str[i].size();
		map[i][s-1] = modulo(i);
		for (int j = s; j <= max_length; j++) map[i][j] = (map[i][j - 1] * 10) % K;
	}
	ll p = dp(0, 0, max_length);
	ll g = gcd(q, p);
	cout<<p/g<<"/"<<q/g;
	

	return 0;
}