#include<iostream>
#define ll long long
using namespace std;

ll N, B;
int N_map[5][5] = { 0, };
int map[5][5] = { 0, };
int temp[5][5] = { 0, };


void mat(int a[5][5], int b[5][5]) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = 0;
			for (int k = 0; k < N; k++) {
				temp[i][j] = (temp[i][j] + (a[i][k] * b[k][j])) % 1000;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = temp[i][j];
		}
	}

}



int main() {

	cin >> N >> B;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
		N_map[i][i] = 1;
	}

	

	while (B > 0) {
		if (B % 2 == 1) mat(N_map, map);
		mat(map, map);

		B /= 2;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << N_map[i][j]<<" ";
		}
		cout << '\n';
	}


	return 0;
}