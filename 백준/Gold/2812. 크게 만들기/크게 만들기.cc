#include <iostream>
#include <deque>
using namespace std;

deque<int> s;

int N, K;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	string str;
	cin >> str;
	int len = N - K;

	for (int i = 0; i < str.size(); i++) {
		int now = str[i] - '0';

		while (1) {
			if (s.empty()) {
				s.push_back(now);
				break;
			}

			if (s.back() >= now || K == 0) {
				s.push_back(now);
				break;
			}
			else{
				s.pop_back();
				K--;
			}
		}
	}

	for (int i = 0; i < len; i++) {
		cout << s.front();
		s.pop_front();
	}


	return 0;
}