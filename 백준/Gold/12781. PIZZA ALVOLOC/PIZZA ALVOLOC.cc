#include <iostream>
#define ll long long
using namespace std;

struct Node{
	int x;
	int y;
};

Node p[4];

int main() {

	for (int i = 0; i < 4; i++) cin >> p[i].x >> p[i].y;


	ll a = (p[1].x - p[0].x) * (p[2].y - p[1].y);
	ll b = (p[2].x - p[1].x) * (p[1].y - p[0].y);
	ll res1 = a - b;

	ll c = (p[1].x - p[0].x) * (p[3].y - p[1].y);
	ll d = (p[3].x - p[1].x) * (p[1].y - p[0].y);
	ll res2 = c - d;
	//cout << res1 << ", " << res2 << '\n';
	ll result = res1 * res2;

	if (result < 0) cout << 1;
	else cout << 0;

	return 0;
}