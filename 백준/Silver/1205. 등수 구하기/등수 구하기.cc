#include <iostream>

using namespace std;

int main() {

	int N, s, P;
	cin >> N >> s >> P;

	int r = 1, p = 0;
	int n;

	for (int i = 0; i < N; i++){
		cin >> n;
		if (n > s) r++;
	}

	if (N == P && n >= s) r = -1;
	cout << r;
	
	return 0;
}