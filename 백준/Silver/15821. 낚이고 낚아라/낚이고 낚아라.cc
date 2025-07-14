#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K, N;
vector<long long> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int P;
		cin >> P;
		long long m = 0;
		for (int j = 0; j < P; j++) {
			long long x, y;
			cin >> x >> y;
			m = max(m, x * x + y * y);
		}
		v.push_back(m);
	}
	
	sort(v.begin(), v.end());

	cout << v[K - 1]<<".00";

	return 0;
}