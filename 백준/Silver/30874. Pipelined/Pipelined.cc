#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

vector<int> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	int max_a = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		max_a = max(max_a, a);
	}
	
	cout << max_a + N - 1;

	return 0;
}