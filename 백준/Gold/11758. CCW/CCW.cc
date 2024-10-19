#include <iostream>

using namespace std;

struct Node{
	int x;
	int y;
};

Node p[3];

int main() {

	for (int i = 0; i < 3; i++) cin >> p[i].x >> p[i].y;
	int a = (p[1].x - p[0].x) * (p[2].y - p[1].y);
	int b = (p[2].x - p[1].x) * (p[1].y - p[0].y);
	int result = a - b;

	if (result > 0) cout << 1;
	else if (result < 0) cout << -1;
	else cout << 0;
	return 0;
}