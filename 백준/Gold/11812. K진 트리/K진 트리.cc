#include <iostream>
#define ll long long
using namespace std;

ll N, K;

int Q;

ll arr[60][2];

int Find_Node(ll a, bool t) {

	int depth = 0;

	arr[depth++][t] = a;

	while (a != 1) {
		a = (a + K - 2) / K;
		arr[depth++][t] = a;
	}

	return depth;
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K >> Q;

	for (int i = 0; i < Q; i++) {
		ll a, b;
		cin >> a >> b;
		
		if (K == 1) {
			cout << abs(a - b) << '\n';
			continue;
		}

		int a_dep = Find_Node(a, 0);
		int b_dep = Find_Node(b, 1);

		int result = a_dep + b_dep;
		int com = 0;
		while (1) {
			ll A = arr[a_dep - com - 1][0];
			ll B = arr[b_dep - com - 1][1];

			if (A != B) break;
			if (A == a || B == b) {
				com++;
				break;
			}
			com++;
		}
		cout << result - (2 * com) << "\n";
	}


	return 0;
}