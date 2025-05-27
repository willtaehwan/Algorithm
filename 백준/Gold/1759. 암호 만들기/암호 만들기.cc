#include <iostream>

using namespace std;

int L, C;
bool arr[27] = { 0, };
bool ans[27] = { 0, };

void dfs(int cnt, int prev) {

	if (cnt == L) {
		int a = 1;
		int b = 2;
		string s = "";
		for (int i = 0; i < 26; i++) {
			if (ans[i]) {
				char c = 'a' + i;
				s.push_back(c);
				if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') a--;
				else b--;
			}
		}
		if (a > 0 || b > 0) return;
		cout << s <<'\n';
		return;
	}

	for (int i = prev+1; i < 26; i++) {
		if (!arr[i]) continue;

		ans[i] = true;
		dfs(cnt + 1, i);
		ans[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char a;
		cin >> a;
		arr[int(a - 'a')] = true;
	}

	dfs(0, -1);

	return 0;
}