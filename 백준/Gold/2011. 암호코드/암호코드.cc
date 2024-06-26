#include <iostream>

#define LIMIT_NUM 1000000

using namespace std;

string pwd;

int prev_num = -1;
int ok = 0;
int end_num = 1;
bool error_flag = false;

void check(int a) {
	int ok_temp = ok % LIMIT_NUM;
	int end_temp = end_num % LIMIT_NUM;
	if (a == 0) {
		if (prev_num == 1 || prev_num == 2) {
			ok = 0;
			end_num = ok_temp;
		}
		else error_flag = true;
	}
	
	if (a == 1 || a == 2) {
		ok = ok_temp + end_temp;
		end_num = ok_temp;
	}
	
	if(a > 2 && ok_temp != 0) {
		ok = 0;
		if (prev_num == 2 && a > 7) end_num = ok_temp + end_temp;
		else end_num = ok_temp * 2 + end_temp;
	}
	

	prev_num = a;
}

int main() {

	cin >> pwd;

	for (int i = 0; i < pwd.size(); i++) {
		int now = pwd[i] - '0';
		check(now);
	}

	if (error_flag) cout << 0;
	else cout << (ok + end_num) % LIMIT_NUM;

	return 0;
}