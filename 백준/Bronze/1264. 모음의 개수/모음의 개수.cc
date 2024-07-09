#include <iostream>
#include <string>
using namespace std;

int main() {

	string str;
	
	while (1) {
		getline(cin, str);
		if (str[0] == '#') break;
		int cnt = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'a') cnt++;
			if (str[i] == 'e') cnt++;
			if (str[i] == 'i') cnt++;
			if (str[i] == 'o') cnt++;
			if (str[i] == 'u') cnt++;
			if (str[i] == 'A') cnt++;
			if (str[i] == 'E') cnt++;
			if (str[i] == 'I') cnt++;
			if (str[i] == 'O') cnt++;
			if (str[i] == 'U') cnt++;
		}
		cout << cnt<<'\n';
	}
	
	
	
	
	return 0;
}