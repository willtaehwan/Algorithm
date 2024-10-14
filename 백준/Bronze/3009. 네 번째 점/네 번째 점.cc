#include <iostream>

using namespace std;

int row[3];
int col[3];

int main() {
	
	for (int i = 0; i < 3; i++) cin >> row[i] >> col[i];
	int r = row[2];
	int c = col[2];
	if (row[2] == row[1]) r = row[0];
	if (row[2] == row[0]) r = row[1];
	if (col[2] == col[1]) c = col[0];
	if (col[2] == col[0]) c = col[1];
	cout << r << " " << c;

	return 0;
}