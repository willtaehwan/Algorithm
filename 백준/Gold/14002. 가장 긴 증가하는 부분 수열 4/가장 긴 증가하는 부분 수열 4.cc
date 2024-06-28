#include <iostream>
#include <stack>
using namespace std;

int N;
int arr[1001];
int DP[1001];

stack<int> st;

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];
	int result = 0;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		DP[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) DP[i] = max(DP[i], DP[j] + 1);
		}
		if (result < DP[i]) {
			result = DP[i];
			idx = i;
		}
	}

	//for (int i = 0; i < N; i++) cout << DP[i] << " ";
	//cout << '\n';
	
	cout << result << '\n';
	//cout << idx << "\n";
	int now_max = arr[idx];
	int now_dp = DP[idx];
	st.push(now_max);
	for (int i = idx; i >= 0; i--) {
		if (now_max > arr[i] && DP[i] == now_dp - 1) {
			now_max = arr[i];
			now_dp--;
			st.push(arr[i]);
		}
	}

	while (!st.empty()) {
		int now = st.top(); st.pop();
		cout << now << " ";
	}

	return 0;
}