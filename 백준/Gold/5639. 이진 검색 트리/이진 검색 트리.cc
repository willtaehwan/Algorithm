#include <iostream>
#include <vector>
using namespace std;

vector<int> n;

void post(int st, int ed) {

	if (st >= ed) return;

	int i = st + 1;
	for (; i < ed; i++) {
		if (n[st] < n[i]) break;
	}

	post(st + 1, i);
	post(i, ed);
	cout << n[st] << '\n';
}


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a;
	/*int N;
	cin >> N;

	int idx = 0;
	for (int i = 0; i < N; i++) {
		cin >> a;
		n.push_back(a);
	}*/

	while (cin >> a) n.push_back(a);

	post(0, n.size());

	return 0;
}