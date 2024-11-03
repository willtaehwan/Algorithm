#include <iostream>
#include <stack>
using namespace std;

int T;

int par[10002] = { 0, };
bool visited[10002] = { 0, };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;

	for (int t = 0; t < T; t++) {

		int N;
		cin >> N;

		for (int i = 0; i <= N; i++) {
			par[i] = 0;
			visited[i] = 0;
		}

		for (int i = 0; i < N - 1; i++) {
			int a, b;
			cin >> a >> b;
			par[b] = a;
		}

		int a, b;
		cin >> a >> b;

		while (a != 0) {
			visited[a] = 1;
			a = par[a];
		}

		int result = 0;
		while (b != 0) {
			if (visited[b]) {
				result = b;
				break;
			}
			b = par[b];
		}
		cout << result<<'\n';

	}

	return 0;
}