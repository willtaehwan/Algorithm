#include <iostream>

using namespace std;

int main() {

	string a, b;
	char n;
	cin >> a >> n >> b;
	int mi = min(a.size(), b.size());
	int ma = max(a.size(), b.size());
	int cnt = a.size() + b.size() - 2;

	if (mi == ma) {
		cnt = a.size() - 1;
		if (n == '+') {
			cout << 2;
			for (int i = 0; i < cnt; i++) cout << 0;
			return 0;
		}
	}

	if (n == '*') {
		
		cout << 1;
		for (int i = 0; i < cnt; i++) cout << 0;
	}
	else {

		cout << 1;
		for (int i = ma-1; i > 0; i--) {
			if (n == '+' && i == mi) {
				cout << 1;
				continue;
			}
			cout << 0;
		}
	}

	return 0;
}