#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	string str;
	int idx;

	bool operator<(Node right) const {
		if (right.str > str) return true;
		return false;
	}

};

int N, M;
string str[1500];
vector<int> ch[1500];

void dfs(int now, int dep) {

	for (int i = 0; i < dep; i++) cout << "--";
	if (now != 0) cout << str[now] << '\n';
	if (ch[now].size() == 0) return;

	vector<Node> so;

	for (int i = 0; i < ch[now].size(); i++) {
		int idx = ch[now][i];
		so.push_back({ str[idx], idx });
	}

	sort(so.begin(), so.end());

	for (int i = 0; i < so.size(); i++) dfs(so[i].idx, dep + 1);

	//for (int i = 0; i < ch[now].size(); i++) dfs(ch[now][i], dep + 1);

	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	int cnt = 1;
	int par = 0;
	bool flag = true;
	string a;
	for (int i = 0; i < N; i++) {
		cin >> M;
		par = 0;
		for (int j = 0; j < M; j++) {
			cin >> a;
			flag = true;
			for (int k = 0; k < ch[par].size(); k++) {
				if (flag && str[ch[par][k]] == a) {
					par = ch[par][k];
					flag = false;
					break;
				}
			}

			if (flag) {
				ch[par].push_back(cnt);
				str[cnt] = a;
				par = cnt;
				cnt++;
			}

		}
	}

	dfs(0, -1);


	return 0;
}