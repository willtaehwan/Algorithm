#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

string N;
int K;

struct Node {
	string val;
	int depth;
};

int invert(string s) {
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		sum *= 10;
		sum += (s[i] - '0');
	}
	return sum;
}

int main() {

	cin >> N >> K;

	int num = N.length();

	if (num == 1) {
		cout << -1 << '\n';
		return 0;
	}

	if (num == 2 && N[1] == '0') {
		cout << -1 << '\n';
		return 0;
	}

	queue<string> q;
	q.push({ N,0 });
	
	int max_result = 0;
	int now_depth = 0;
	while (!q.empty() && now_depth < K) {
		
		int Q_size = q.size();
		set<string> se;

		for (int qs = 0; qs < Q_size; qs++) {
			string now = q.front(); q.pop();

			for (int i = 0; i < num - 1; i++) {
				for (int j = i + 1; j < num; j++) {

					swap(now[i], now[j]);

					if (se.find(now) == se.end()) {
						if (now_depth == K - 1 && max_result < invert(now)) max_result = invert(now);
						q.push(now);
						se.insert(now);
					}
					swap(now[i], now[j]);
				}
			}
		}
		now_depth++;
		

	}
	if (now_depth != K) cout << -1 << '\n';
	cout << max_result;

	return 0;
}