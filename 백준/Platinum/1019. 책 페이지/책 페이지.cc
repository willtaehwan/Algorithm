#include <iostream>
#define ll long long
using namespace std;

int N;

ll arr2[10];

ll sqr(int n) {
	ll ans = 1;
	for (int i = 1; i <= n; i++) ans *= 10;
	return ans;
}

void calc(int n, int k) {
	if (n == 0) {
		for (int i = 1; i <= k; i++) arr2[i]++;
		return;
	}

	int t = 0;
	for (int i = 1; i <= n-1; i++) t = t * 10 + 1;
	ll s = sqr(n - 1);
	arr2[0] += s * (n-1) - t + n;
	
	for (int i = 1; i < 10; i++) {
		arr2[i] += s * n;
		if (i == k) arr2[i]++;
		if (i < k) arr2[i] += s*10;
	}
	for (int i = 0; i < 10; i++) arr2[i] += s * n * (k - 1);

}

ll zero_p(int n, ll next) {
	ll result = 0;
	ll temp = 9;
	while (n--) {
		if (next > temp) result += temp;
		else result += next;
		temp = temp * 10 + 9;
	}

	return result;
}

void req(int num) {
	if (num <= 0) return;

	int k = num%10, n = 0;
	int t = num;
	while (t >= 10) {
		n++;
		t /= 10;
		if (t < 10) k = t;
	}
	calc(n, k);
	//cout << n << ", " << k << '\n';
	int next = num % (sqr(n));
	arr2[k] += next;
	if(n > 1) arr2[0] += zero_p(n-1, next);
	req(next);
}


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10; i++) arr2[i] = 0;

	cin >> N;

	req(N);

	for (int i = 0; i < 10; i++) cout << arr2[i] << " ";
	
	return 0;
}