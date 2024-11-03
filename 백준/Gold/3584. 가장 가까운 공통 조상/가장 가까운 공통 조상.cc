#include <iostream>
#include <stack>
using namespace std;

int T;

int par[10002] = { 0, };

int main() {

	cin >> T;

	for (int t = 0; t < T; t++) {

		int N;
		cin >> N;

		for (int i = 0; i <= N; i++) par[i] = 0;

		for (int i = 0; i < N - 1; i++) {
			int a, b;
			cin >> a >> b;
			par[b] = a;
		}

		int a, b;
		cin >> a >> b;
		stack<int> s1;
		stack<int> s2;

		while (a != 0 || b != 0) {
			if(a != 0) s1.push(a);
			if(b != 0) s2.push(b);
			a = par[a];
			b = par[b];
		}
		int prev = 0;
		//cout << "===============================\n";
		while (!s1.empty() && !s2.empty()) {
			int n1 = s1.top(); s1.pop();
			int n2 = s2.top(); s2.pop();
			//cout << n1 << ", " << n2 << '\n';
			if (n1 == n2) prev = n1;
			else break;
		}
		cout << prev<<'\n';
	}

	return 0;
}