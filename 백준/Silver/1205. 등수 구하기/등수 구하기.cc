#include <iostream>

using namespace std;

int main() {

	int N, score, P;
	cin >> N >> score >> P;

	int rank = 1, p = 0;
	int n;

	for (int i = 0; i < N; i++){
		cin >> n;
		if (n > score) rank++;
	}

	if (N == P && n >= score) rank = -1;
	cout << rank;
	
	return 0;
}