#include <iostream>

using namespace std;

struct Tree {
	int left;
	int right;
};

int N;

bool visited[100010] = { 0, };

int io[100010] = { 0, };
int po[100010] = { 0, };
Tree tr[100010];

void dfs(int now) {

	if (now == 0) return;

	cout << now << " ";

	dfs(tr[now].left);
	dfs(tr[now].right);

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++)cin >> io[i];
	for (int i = 0; i < N; i++)cin >> po[i];

	int ix = 0;
	int px = 0;
	int prev = 0;
	int Root = 0;
	bool flag = false;
	while (1) {
		if (px == N) break;
		//cout << io[ix] << ", " << po[px] << "  prev : " << prev << '\n';
		int now_i = io[ix];
		int now_p = po[px];

		if (now_i == now_p) {
			if (tr[now_i].left == 0) tr[now_i].left = prev;
			prev = now_i;
			ix++;
			px++;
			visited[prev] = true;
			flag = true;
			continue;
		}

		if (now_i != now_p) {
			flag = false;
			if (visited[now_p]) {
				tr[now_p].right = po[px - 1];
				prev = now_p;
				px++;
				continue;
			}

			if (!visited[now_p]) {
				if (tr[now_i].left == 0) {
					tr[now_i].left = prev;
					prev = 0;
				}
				visited[now_i] = true;
				ix++;
				continue;
			}

		}



	}
	/*cout << '\n';
	cout << "ROOT = " << prev << '\n';
	for (int i = 1; i <= N; i++) {
		cout << i << " : " << tr[i].left << " , " << tr[i].right << '\n';
	}*/

	dfs(prev);


	return 0;
}