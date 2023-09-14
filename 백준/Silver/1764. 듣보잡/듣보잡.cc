#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;

map<string, int> um;
vector<string> v;
priority_queue<string> pq;
stack<string> st;
int main() {

	int N, M;

	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		um.insert({ row,1 });
	}
	int cnt = 0;
	for (int j = 0; j < M; j++) {
		string row;
		cin >> row;
		if (um.find(row) == um.end()) {
			continue;
		}
		else {
			pq.push(row);
			cnt++;
		}
		
	}

	cout << cnt<<endl;
	while (!pq.empty()) {
		string now = pq.top(); pq.pop();
		st.push(now);
	}

	while (!st.empty()) {
		string now = st.top(); st.pop();
		cout << now << endl;
	}

	return 0;
}