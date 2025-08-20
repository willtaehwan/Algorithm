#include <iostream>

using namespace std;

int T, G = 0;

int check(int a) {

	int ta = a;
	int mc = 6;

	if (a == G) return 0;

	for (int i = 1; i < 6; i++) {
		ta += 20;
		if (ta > 2000) ta = 0;
		if (ta == G) mc = min(mc, i);
	}
	ta = a;
	for (int i = 1; i < 6; i++) {
		ta -= 20;
		if (ta < 0) ta = 2000;
		if (ta == G) mc = min(mc, i);
	}

	return mc;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		string a, b, g;
		char ch;
		int A = 0, B = 0;

		cin >> a >> b >> ch >> g;

		A = int(a[2] - '4') * 1000 + int(a[4] - '0') * 100 + int(a[5] - '0') * 10 + int(a[6] - '0');
		B = int(b[2] - '4') * 1000 + int(b[4] - '0') * 100 + int(b[5] - '0') * 10 + int(b[6] - '0');
		G = int(g[2] - '4') * 1000 + int(g[4] - '0') * 100 + int(g[5] - '0') * 10 + int(g[6] - '0');
		
		int cA = check(A);
		int cB = check(B);

		if (ch == 'A') cB++;
		else cA++;

		cout << min(cA, cB)<<'\n';

	}


	return 0;
}