#include <iostream>
#include <string>
using namespace std;

string str;

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	
	int num = 0;
	int ptr = 0;
	while (ptr != str.size()) {
		num++;
		string ns = to_string(num);
		for (int i = 0; i < ns.size(); i++) {
			if (str[ptr] == ns[i]) ptr++;
		}
	}

	cout << num;

	return 0;
}