#include <iostream>
using namespace std;

int N, M, a, s = 0;
unsigned int r[1002] = { 1 };
long long ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M;
	while (N--) {
		cin >> a;
		s = (s + a) % M;
		ans += r[s]++;
	}
	cout << ans;
	return 0;
}