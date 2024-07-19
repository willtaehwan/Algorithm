#include <iostream>
#include <queue>

#define ll long long

using namespace std;

int T;

int main() {

	cin >> T;
	priority_queue<ll, vector<ll>, greater<ll>> pq;

	for (int tc = 0; tc < T; tc++) {
		ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		int K;
		cin >> K;
		
		for (int i = 0; i < K; i++) {
			int now;
			cin >> now;
			pq.push(now);
		}

		ll result = 0;
		while (!pq.empty()) {
			if (pq.size() > 1) {
				ll now1 = pq.top(); pq.pop();
				ll now2 = pq.top(); pq.pop();

				result += now1 + now2;
				//cout << now1 << ", " << now2<<" = "<<result<<'\n';
				pq.push(now1 + now2);
			}
			else pq.pop();
				
		}
		cout << result << '\n';
	}


	return 0;
}