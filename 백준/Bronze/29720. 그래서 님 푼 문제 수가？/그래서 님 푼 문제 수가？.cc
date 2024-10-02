#include <iostream>

using namespace std;

int main() {

	int N, M, K;
	cin >> N >> M >> K;
	int a = N - M * (K - 1);
	
	if (a - M <= 0) cout << 0 << " ";
	else cout << a - M << " ";

	cout << a - 1;

	return 0;
}