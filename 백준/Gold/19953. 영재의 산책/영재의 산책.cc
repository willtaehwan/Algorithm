#include <iostream>
using namespace std;

int v, m, t;

int ta[4] = { 0, };
int cnt[4] = { 0, };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> v >> m >> t;
	
	int r = 0, c = v;

	v = (v * m) % 10;

	for (int i = 0; i < 4; i++) {
		ta[i] = v;
		v = (v * m) % 10;
	}
	
	for (int i = 0; i < 4; i++) cnt[i] = (t - 1) / 4;
	for (int i = 0; i < (t - 1) % 4; i++) cnt[i]++;

	r += ta[0] * cnt[0] - ta[2] * cnt[2];
	c += ta[3] * cnt[3] - ta[1] * cnt[1];

	cout << r << " " << c;

	return 0;
}