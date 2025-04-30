#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int p;
	int l;
	int r;
};

Node n[1000001];

void o_o(int a) {

	if (n[a].l != 0) o_o(n[a].l);
	if (n[a].r != 0) o_o(n[a].r);
	if (a != 0) cout << a <<"\n";
}

void p_o(int p, int a) {

	if (p > a) {
		if (n[p].l == 0) {
			n[p].l = a;
			n[a].p = p;
			return;
		}
		p_o(n[p].l, a);
	}
	else {
		if (n[p].r == 0) {
			n[p].r = a;
			n[a].p = p;
			return;
		}
		p_o(n[p].r, a);
	}
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a;
    
	/*
	vector<int> v;
	for (int i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
		p_o(0, a);
	}

	for (int i = 0; i < v.size(); i++) {
		int now = v[i];
		cout << now<<" "<<n[now].p << " " << n[now].l << " " << n[now].r << '\n';
	}
	*/

	while (cin >> a) p_o(0, a);

	o_o(0);

	return 0;
}