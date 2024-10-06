#include <iostream>
#define ll long long
using namespace std;

struct Node {
	int a;
	int c;
	int b;
};

int N;
Node arr[20010];

ll check(ll mid) {

	ll cnt = 0;

	for (int i = 0; i < N; i++) {
		ll max = (ll)arr[i].c;
		if (max > mid) max = mid;

		if (arr[i].a > max) continue;
		ll k = (max - arr[i].a) / (ll)arr[i].b + 1;
		cnt += k;
	}
	//cout << cnt << '\n';
	return cnt;
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].a >> arr[i].c >> arr[i].b;
	
	ll left = 0;
	ll right = 2147483647;
	ll result = -1;
	
	while (left <= right) {
		ll mid = (right + left)/2;
		
		//cout << "re : " << left << ", " << right << '\n';
		
		if (check(mid) % 2 == 1) {
			right = mid;
			result = mid;
			if (left == right) break;
		}
		else left = mid + 1;
		
	}

	if (result == -1) cout << "NOTHING";
	else cout << result << " " << check(result) - check(result - 1);

	return 0;
}