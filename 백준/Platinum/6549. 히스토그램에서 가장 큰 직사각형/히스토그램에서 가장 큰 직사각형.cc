#include <iostream>
#include <vector>
#include <stack>
typedef long long ll;
using namespace std;

int N;

int main() {

	while (1) {

		cin >> N;
		if (N == 0) break;
		vector<ll> v(N + 2);
		ll result = 0;
		v[0] = 0;
		v[N+1] = 0;
		for (int i = 1; i <= N; i++) cin >> v[i];

		stack<ll> s;

		for (int i = 1; i <= N+1; i++) {
			
			while (!s.empty() && v[s.top()] >= v[i]) {
				int temp = s.top(); s.pop();
				int width = i - ((s.empty()) ? 0 : s.top()) - 1;
				if (result < v[temp] * width) result = v[temp] * width;
				//cout << i << " " << v[temp] << " " << width<<'\n';
			}
			s.push(i);
		}

		cout << result << '\n';

	}


	return 0;
}