#include <iostream>
using namespace std;
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int ml = 0;
	int prev = 0;
	for(int i = 0; i<M;i++){
		int now;
		cin >> now;
		ml = max(ml, (now - prev + 1) / 2);
		if (i == 0) ml = now;
		prev = now;
	}
	cout << max(ml, N - prev);
	return 0;
}