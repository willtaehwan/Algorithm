#include <iostream>
#define MAX 1000002
using namespace std;

int arr[MAX] = { 0, };

string str;

void k_search(int now, int prev) {
	if (str[prev] == str[now - 1]) arr[now] = prev + 1;
	else if (prev != 0) k_search(now, arr[prev]);
}


int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (1) {
		cin >> str;
		if (str == ".") break;

		bool zero_flag = true;
		bool ans_flag = false;
		int n = 1;
		for (int i = 0; i <= str.size(); i++) arr[i] = 0;
		for (int i = 2; i <= str.size(); i++) k_search(i, arr[i - 1]);

		int s = str.size();
		int p = arr[s]; //A(n - 1)
		int a = s - p; // 
		
		if (a <= p && p % a == 0) n = s / a;

		cout << n << '\n';
	}


	return 0;
}