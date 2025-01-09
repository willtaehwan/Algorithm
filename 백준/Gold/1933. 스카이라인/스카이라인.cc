#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int x;
	int lr;
	int h;
	int idx;
	
	bool operator<(Node right) const {
		if (x > right.x) return true;
		else if (x < right.x) return false;

		if (lr > right.lr) return true;
		else if (lr < right.lr) return false;

		if (h < right.h) return true;
		else if (h > right.h) return false;

		if (idx > right.idx) return true;
		else return false;
	}

};

struct Node2 {
	int x;
	int h;
	int idx;

	bool operator<(Node2 right) const {
		if (h < right.h) return true;
		else return false;
	}
};

int N;
bool checked[100010] = { 0, };

priority_queue<Node> q;
priority_queue<Node2> q2;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int l, h, r;
		cin >> l >> h >> r;
		q.push({ l,1, h, i });
		q.push({ r,0, h, i });
	}

	q2.push({0, 0, 0 });
	checked[0] = true;
	int max_h = 0;
	int max_idx = 0;

	while (!q.empty()) {
		Node now = q.top(); q.pop();
		//cout << now.x << "\n";
		bool flag = true;
		if (checked[now.idx]) {
			checked[now.idx] = false;
			flag = false;
			//cout << now.idx << "  OFF \n";
			if (max_idx == now.idx) {
				//cout <<"SAME H : " << now.x << "\n";
				q2.pop();
				bool ch_flag = true;

				if (q.empty()) {
					cout << now.x << " " << 0;
					continue;
				}
				//cout<<"QTOP = " << q.top().idx << '\n';
				if (q.top().x == now.x) {
					//cout << "same x : " << q.top().x << " \n";
					while (!q.empty()) {
						Node ne = q.top();
						
						if (ne.x == now.x) {
							if (checked[ne.idx]) {
								checked[ne.idx] = false;
								q.pop();
								continue;
							}
							else {
								ch_flag = false;
								if (ne.h == now.h) {
									max_idx = ne.idx;
									break;
								}
								else {
									max_h = ne.h;
									max_idx = ne.idx;
									cout << now.x << " " << max_h << " ";
									break;
								}
							}
						}
						else break;
					}
				}
				

				if (!ch_flag) continue;

				while (!q2.empty()) {
					Node2 next = q2.top();
					//cout << "   NEXT : " << next.x << " " << next.h << " "<<checked[next.idx] << '\n';
					if (checked[next.idx]) {
						max_h = next.h;
						max_idx = next.idx;
						cout << now.x << " " << next.h << " ";
						break;
					}
					else q2.pop();
				}
			}
		}

		if (!flag) continue;

		q2.push({now.x, now.h, now.idx });
		checked[now.idx] = true;
		//cout << now.idx << "  ON \n";
		if (max_h < now.h) {
			max_h = now.h;
			max_idx = now.idx;
			cout << now.x << " " << now.h << " ";
		}
	}


	return 0;
}