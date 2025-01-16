#include <iostream>

using namespace std;

int N, M;
int arr[100001] = { 0, };
string s[100001];
int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		string str;
		int a;
		cin >> str >> a;
		if (i != 0 && arr[cnt - 1] == a) continue;
		s[cnt] = str;
		arr[cnt] = a;
		cnt++;
	}

	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		int left = 0;
		int right = cnt - 1;
		int mid = (left + right) / 2;
		while (left <= right) {
			mid = (left + right) / 2;

			if (arr[mid] == n) break;
			
			if (left == right) {
				mid = left;
				break;
			}
			if (arr[mid] < n) left = mid + 1;
			if (arr[mid] > n) right = mid;
		}
		cout << s[mid] << '\n';
	}

	return 0;
}