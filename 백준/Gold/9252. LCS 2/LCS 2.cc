#include <iostream>
#include <vector>
using namespace std;

int map[1003][1003] = { 0, };

int dr[] = { -1,0 };
int dc[] = { 0,-1 };

string row1, row2;

vector<char> v;

void dp(int lr, int lc){
	
	if (map[lr][lc] == 0) {
		v.push_back(row1[lr]);
		return;
	}

	int rner = lr - 1;
	int rnec = lc - 1;
	for (int i = 0; i < 2; i++) {
		int ner = lr + dr[i];
		int nec = lc + dc[i];

		if (map[ner][nec] == map[lr][lc]) {
			rner = ner;
			rnec = nec;
			break;
		}
	}
	//cout << rner << " " << rnec << endl;
	dp(rner, rnec);

	if (row1[lr] == row2[lc]) {
		//cout << lr <<" "<< lc << endl;
		v.push_back(row1[lr]);
		return;
	}

	return;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> row1;
	cin >> row2;
	int result = 0;
	int lastrow = 0;
	int lastcol = 0;
	for (int i = 1; i <= row1.size(); i++) {
		for (int j = 1; j <= row2.size(); j++) {
			if (row1[i - 1] == row2[j - 1]) {
				map[i][j] = map[i - 1][j - 1] + 1;
				if (result < map[i][j]) {
					lastrow = i;
					lastcol = j;
					result = map[i][j];
				}
			}
			else {
				map[i][j] = max(map[i - 1][j], map[i][j - 1]);
			}
		}
	}

	/*for (int i = 0; i <= row1.size(); i++) {
		for (int j = 0; j <= row2.size(); j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << lastrow<<" "<<lastcol<<endl;*/

	dp(lastrow, lastcol);

	cout << result << endl;

	if (result != 0) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
	}

	

	return 0;
}