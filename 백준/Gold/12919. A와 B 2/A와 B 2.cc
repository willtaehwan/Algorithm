#include <iostream>

using namespace std;

string S, T;

void check_in(string t) {

	if (t == S) {
		cout << 1;
		exit(0);
	}

	if (t.size() == S.size()) return;

	if (t[0] == 'B') {
		string new_t = "";
		for (int i = t.size() - 1; i > 0; i--)new_t.push_back(t[i]);
		check_in(new_t);
	}

	if (t[t.size() - 1] == 'A') {
		string new_t = "";
		for (int i = 0; i < t.size() - 1; i++) new_t.push_back(t[i]);
		check_in(new_t);
	}

}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	cin >> T;

	check_in(T);

	cout << 0;

	return 0;
}