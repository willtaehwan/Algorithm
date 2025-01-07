#include <iostream>

using namespace std;

int N;
string str;
bool arr[2][100001] = { 0, };
bool tar[100001] = { 0, };
int min_result = 1e9;

void switch_on(int ch, int idx, int cnt) {
	
	//for (int i = 0; i < N; i++)cout << arr[ch][i];
	//cout <<"  :  " << cnt << '\n';

	if (idx == N) {
		if (tar[N -1] == arr[ch][N - 1]) min_result = min(min_result, cnt);
		return;
	}

	if (arr[ch][idx - 1] == tar[idx - 1]) switch_on(ch, idx + 1, cnt);
	else {
		arr[ch][idx - 1] = !(arr[ch][idx - 1]);
		arr[ch][idx] = !(arr[ch][idx]);
		arr[ch][idx + 1] = !(arr[ch][idx + 1]);
		switch_on(ch, idx + 1, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++) {
		arr[0][i] = int(str[i] - '0');
		arr[1][i] = arr[0][i];
	}
	cin >> str;
	for (int i = 0; i < N; i++) tar[i] = int(str[i] - '0');

	arr[1][0] = !(arr[1][0]);
	arr[1][1] = !(arr[1][1]);

	/*for (int i = 0; i < N; i++) cout << arr[0][i];
	cout << '\n';
	for (int i = 0; i < N; i++) cout << arr[1][i];
	cout << '\n';
	for (int i = 0; i < N; i++) cout << tar[i];
	cout << "\n\n";*/

	switch_on(0, 1, 0);

	//cout << '\n';

	switch_on(1, 1, 1);

	if (min_result == 1e9) cout << -1;
	else cout << min_result;

	return 0;
}