#include <iostream>
#include <stack>
using namespace std;

int N;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	int cnt = 0;
	stack<int> s;
	s.push(0);
	for (int i = 0; i <= N; i++) {
		int a, b;
		
		if (i == N) b = 0;
		else cin >> a >> b;

		int now = s.top();
		if (now > b){
			//cout <<"DETECTED  " << now << " " << b << '\n';
			while (!s.empty()) {
				if (s.top() > b) {
					//cout <<"BOOM  " << s.top() << " " << b << '\n';
					s.pop();
					cnt++;
				}
				else if (s.top() == b) s.pop();
				else break;
			}
		}
		s.push(b);
	}

	cout << cnt;

	return 0;
}