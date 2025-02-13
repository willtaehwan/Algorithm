#include <iostream>
#include <vector>
#include<stack>
using namespace std;

struct Node {
	int cnt;
	int mi;
};

struct St {
	int idx;
	int si;
};

int N;
int arr[100004] = { 0, };
int cnt[100004] = { 0, };
int mi[100004] = { 0, };

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		mi[i] = 1e9;
	}
	stack<St> sl;
	for (int i = N - 1; i > 0; i--) {
		if (arr[i + 1] > arr[i]) sl.push({ i + 1, arr[i + 1] });

		while (!sl.empty()) {
			St now = sl.top();
			if (now.si <= arr[i]) sl.pop();
			else {
				cnt[i] += sl.size();
				mi[i] = now.idx;
				break;
			}
		}
	}

	stack<St> sr;
	for (int i = 2; i <= N; i++) {
		if (arr[i-1] > arr[i]) sr.push({ i-1, arr[i-1] });
		
		while (!sr.empty()) {
			St now = sr.top();
			if (now.si <= arr[i]) sr.pop();
			else {
				cnt[i] += sr.size();
				if (mi[i] - i >= i - now.idx) mi[i] = now.idx;
				break;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << cnt[i];
		if(cnt[i] != 0) cout << " " << mi[i];
		cout << '\n';
	}



	return 0;
}