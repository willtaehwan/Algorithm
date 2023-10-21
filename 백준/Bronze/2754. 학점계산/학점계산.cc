#include <iostream>

using namespace std;

string row;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> row;

	int a = 4 - int(row[0] - 'A');
	int b = 0;

	if (row[1] == '+') b = 3;
	else if (row[1] == '0') b = 0;
	else {
		b = 7;
		a--;
	}
	if (row[0] == 'F') cout << "0.0";
	else cout << a <<"."<< b;


	return 0;
}