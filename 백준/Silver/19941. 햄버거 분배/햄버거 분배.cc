#include <iostream>

using namespace std;

int N, K;
string str;

bool ham[20001] = { 0, };

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'P') {
			for (int j = -K; j <= K; j++) {
				int ch = i + j;
				if (ch < 0 || ch >= N) continue;
				if (str[ch] == 'P') continue;
				if (ham[ch]) continue;
				ham[ch] = true;
				cnt++;
				break;
			}
		}
	}

	cout << cnt;

	return 0;
}