#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int a;
	int b;
	int c;
};

bool check[1001][1001] = { 0, };


int bfs(int a, int b, int c) {

	queue<Node> q;
	int temp[3] = { a,b,c };
	sort(temp, temp + 3);
	q.push({ temp[0], temp[1], temp[2] });

	while (!q.empty()) {
		Node now = q.front(); q.pop();
		int m[3] = { now.a, now.b, now.c };
		sort(m, m + 3);

		if (check[m[0]][m[1]]) continue;

		check[m[0]][m[1]] = true;

		if (now.a == now.b && now.b == now.c) return 1;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				if (m[i] - m[j] == 0) continue;

				if (m[i] - m[j] > 0) q.push({ m[i] - m[j], m[3 - i - j], m[j] * 2 });
				else q.push({ m[i] * 2, m[3 - i - j], m[j] - m[i] });
			}
		}
	}

	return 0;
}

int main() {
	
	int A, B, C;
	cin >> A >> B >> C;

	if ((A + B + C) % 3 != 0) cout << 0;
	else cout<<bfs(A, B, C);

	return 0;
}