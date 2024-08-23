#include <iostream>
#define ll long long
using namespace std;

int N, K;

int map[15][750]; // i번째 숫자가 K자리부터 시작할 때 나머지
ll arr[100][32768]; // [확인한 숫자 상태 표시][현재 나머지] 일 때 가능한 경우의 수

string str[15];

int max_length = 0;

int modulo(int idx) {

	int res = 0;
	for (int i = 0; i < str[idx].size(); i++) {
		res = (res * 10 + (str[idx][i] - '0')) % K;
	}
	return res;
}

ll dp(int mod, int stat) {
	
	if (stat == (1 << N) - 1) {
		if (mod == 0) return 1;
		else return 0;
	}

	if (arr[mod][stat] != -1) return arr[mod][stat];

	int now_len = max_length;
	for (int i = 0; i < N; i++) {
		if (stat & (1 << i)) now_len -= str[i].size();
	}

	ll result = 0;
	for (int i = 0; i < N; i++) {
		if (stat & (1 << i)) continue;
		int next_st = stat + (1 << i);
		int next_mod = (mod + map[i][now_len]) % K;
		result += dp(next_mod ,next_st);
	}
	arr[mod][stat] = result;
	return arr[mod][stat];
}

ll gcd(ll a, ll b){
	return b ? gcd(b, (a % b)) : a;
}

int main() {

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
	for (int i = 0; i < K; i++) fill_n(arr[i], size(arr[i]), -1);

	for (int i = 0; i < N; i++) {
		int s = str[i].size();
		map[i][s-1] = modulo(i);
		for (int j = s; j <= max_length; j++) map[i][j] = (map[i][j - 1] * 10) % K;
	}
	ll p = dp(0, 0);
	ll g = gcd(q, p);
	cout<<p/g<<"/"<<q/g;
	

	return 0;
}