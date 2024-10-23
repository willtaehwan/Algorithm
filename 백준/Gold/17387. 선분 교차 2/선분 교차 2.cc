#include <iostream>
#define ll long long
using namespace std;

struct Node {
	ll x;
	ll y;
};

Node p[4];

bool flag = true;
bool in_flag = false;

int ccw(int a, int b, int c) {
	ll res1 = (p[b].x - p[a].x) * (p[c].y - p[b].y);
	ll res2 = (p[c].x - p[b].x) * (p[b].y - p[a].y);

	//cout <<a<< ", "<<b<<", "<<c<<" : "<< res1 - res2 << '\n';

	if (res1 - res2 < 0) return -1;
	if (res1 - res2 > 0) return 1;

	ll low_x = min(p[a].x, p[b].x);
	ll high_x = max(p[a].x, p[b].x);
	ll low_y = min(p[a].y, p[b].y);
	ll high_y = max(p[a].y, p[b].y);
	if (low_x <= p[c].x && high_x >= p[c].x && low_y <= p[c].y && high_y >= p[c].y) in_flag = true;

	return 0;
}

int main() {
	
	for (int i = 0; i < 4; i++) cin >> p[i].x >> p[i].y;

	int case1 = ccw(0, 1, 2) * ccw(0, 1, 3);
	int case2 = ccw(2, 3, 0) * ccw(2, 3, 1);
	if (case1 >= 0) flag = false;
	if (case2 >= 0) flag = false;

	if (flag||in_flag) cout << 1;
	else cout << 0;

	return 0;
}