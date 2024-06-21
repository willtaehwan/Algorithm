#include <iostream>

using namespace std;

int N, M;

int main() {

	cin >> N >> M;
	int max_length = 0;
	int edge_length = 0;
	int prev = 0;
	for (int i = 0; i < M; i++) {
		int now;
		cin >> now;
		if (now - prev > max_length) {
			max_length = now - prev;
			if (i == 0) edge_length = now - prev;
		}
		prev = now;
	}

	if (N - prev > edge_length) edge_length = N - prev;

	
	if (max_length/2 < edge_length) cout << edge_length;
	else cout << (max_length / 2) + (max_length % 2) ;

	return 0;
}