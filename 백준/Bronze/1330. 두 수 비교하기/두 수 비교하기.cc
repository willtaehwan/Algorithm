#include <iostream>

using namespace std;

int N, M;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	if (N > M) cout << ">";
	else if (N < M) cout << "<";
	else cout << "==";

	return 0;
}