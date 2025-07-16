#include <iostream>
#include <queue>
#define ll long long 
using namespace std;

ll N;
bool arr[10];

bool check_num(ll n) {

	bool flag = false;
	for (ll i = 1; i < 10; i++) {
		if (!arr[i]) continue;
		if (n % i != 0) flag = true;
	}

	return flag;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	ll temp = N;
	while (temp > 0) {
		arr[temp % 10] = true;
		temp /= 10;
	}

	temp = N;
	int k = 10;
	int b = 0;

	while (check_num(temp)) {
		temp = N * k + b;
		b++;
		if (b == k) {
			k *= 10;
			b = 0;
		}
	}
	
	cout << temp;

	return 0;
}