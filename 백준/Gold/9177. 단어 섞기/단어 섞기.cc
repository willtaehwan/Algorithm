#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row;
	int col;
	int num;
};

int N;

int st[201][201] = { 0, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int n = 1; n <= N; n++) {

		string st1;
		string st2;
		string st3;
		cin >> st1 >> st2 >> st3;

		for (int i = 0; i <= st2.size(); i++) {
			for (int j = 0; j <= st1.size(); j++) {
				st[i][j] = -1;
			}
		}

		queue<Node> q;
		q.push({ 0, 0, 0 });
		
		bool flag = false;
		while (!q.empty()) {
			Node now = q.front(); q.pop();
			
			if (st[now.row][now.col] != -1) continue;

			if (now.row == st2.size() && now.col == st1.size()) {
				flag = true;
				break;
			}
			if (now.num > st3.size()) break;
			
			if (st3[now.num] == st1[now.col]) {
				st[now.row][now.col] = now.num;
				q.push({ now.row, now.col + 1, now.num + 1 });
			}
			if (st3[now.num] == st2[now.row]) {
				st[now.row][now.col] = now.num;
				q.push({ now.row + 1, now.col, now.num + 1 });
			}

		}
		
		/*for (int i = 0; i <= st2.size(); i++) {
			for (int j = 0; j <= st1.size(); j++) {
				cout << st[i][j] << " ";
			}
			cout << '\n';
		}*/

		if(flag) cout << "Data set " << n << ": yes\n";
		else cout << "Data set " << n << ": no\n";

	}


	return 0;
}