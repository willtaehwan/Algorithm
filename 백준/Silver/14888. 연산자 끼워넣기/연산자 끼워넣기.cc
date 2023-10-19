#include <iostream>

using namespace std;

int N;
int arr[12] = { 0, };
int oper[4] = { 0, };
int cnt = 0;
int max_result = -1e9;
int min_result = 1e9;

void dfs(int now) {

	if (cnt == N-1) {
		if (now > max_result) {
			max_result = now;
		}
		if (now < min_result) {
			min_result = now;
		}
		return;
	}


	for (int i = 0; i < 4; i++) {
		int next = now;
		if (oper[i] == 0) continue;
		
		if (i == 0) next += arr[cnt+1];
		else if (i == 1) next -= arr[cnt+1];
		else if (i == 2) next *= arr[cnt+1];
		else next /= arr[cnt+1];

		oper[i]--;
		cnt++;
		dfs(next);
		cnt--;
		oper[i]++;

	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}


	cnt = 0;
	dfs(arr[0]);

	cout << max_result << endl;
	cout << min_result;


	return 0;
}