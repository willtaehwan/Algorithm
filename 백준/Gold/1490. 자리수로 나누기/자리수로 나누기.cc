#include <iostream>
#include <queue>
#define ll long long 
using namespace std;

ll N;
bool arr[10];
bool c = true;

bool check_num(ll n) {

	bool flag = true;
	for (ll i = 1; i < 10; i++) {
		if (!arr[i]) continue;
		if (n % i != 0) flag = false;
	}

	return flag;
}


void bfs(ll st) {

	queue<ll> q;
	q.push(st);

	while (c) {
		ll now = q.front(); q.pop();
		for (ll i = 0; i < 10; i++) {
			ll t = now + i;
			if (check_num(t)) {
				cout << t;
				c = false;
				break;
			}
			q.push(t * 10);
		}
		
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	ll temp = N;
	while (temp > 0) {
		arr[temp % 10] = true;
		temp /= 10;
	}

	if (check_num(N)) {
		cout << N;
		return 0;
	}

	bfs(N * 10);

	return 0;
}