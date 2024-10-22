#include <iostream>
#define ll long long
using namespace std;

struct Node {
	ll x;
	ll y;
};

Node p[4];

int ccw(int a, int b, int c) {
	ll res1 = (p[b].x - p[a].x) * (p[c].y - p[b].y);
	ll res2 = (p[c].x - p[b].x) * (p[b].y - p[a].y);
	if (res1 - res2 < 0) return -1;
	if (res1 - res2 > 0) return 1;
	return 0;
}

int main() {
	bool flag = true;
	for (int i = 0; i < 4; i++) cin >> p[i].x >> p[i].y;

	if (ccw(0, 1, 2) * ccw(0, 1, 3) > 0) flag = false;
	if (ccw(2, 3, 0) * ccw(2, 3, 1) > 0) flag = false;

	if (flag) cout << 1;
	else cout << 0;

	return 0;
}