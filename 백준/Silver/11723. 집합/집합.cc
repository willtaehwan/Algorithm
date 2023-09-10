#include <iostream>
#include <cstring>
using namespace std;

int DAT[21] = { 0, };

int N,a;
string row="";

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		
		
		cin >> row;
		if (row == "check") {
			cin >> a;
			cout << DAT[a] << "\n";
		}
		else if (row == "add") {
			cin >> a;
			if (DAT[a] == 1) continue;
			else DAT[a] = 1;
		}
		else if (row == "remove") {
			cin >> a;
			if (DAT[a] == 1) DAT[a] = 0;
			else continue;
		}
		else if (row == "toggle") {
			cin >> a;
			if (DAT[a] == 1) DAT[a] = 0;
			else DAT[a] = 1;
		}
		else if (row == "all") {
			for (int i = 1; i < 21; i++) {
				DAT[i] = 1;
			}
		}
		else if (row == "empty") {
			memset(DAT, 0, sizeof(DAT));
		}

	}


	return 0;
}