#include <iostream>
#define MAX 5001
using namespace std;

string P;
int arr[MAX] = { 0, };
int max_length = 0;

void k_search(int now, int prev, int st) {
	if (P[prev] == P[now - 1]) {
		arr[now] = prev + 1;
		max_length = max(max_length, arr[now] - st);
	}
	else if (prev != st) k_search(now, arr[prev], st);
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> P;
	
	for(int st = 0; st<P.size()-1;st++){
		arr[st] = st;
		arr[st + 1] = st;
		for (int i = st + 2; i <= P.size(); i++) {
			arr[i] = st;
			k_search(i, arr[i - 1], st);
		}
	}

	cout << max_length;

	return 0;
}