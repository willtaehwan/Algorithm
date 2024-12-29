#include <iostream>

using namespace std;

int N;

string f_str;
string str[101];

int f_arr[26] = { 0, };
int p_arr[26] = { 0, };

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	cin >> f_str;
	for (int i = 0; i < f_str.size(); i++) f_arr[(int)(f_str[i] - 'A')]++;
	int result = 0;

	for (int i = 0; i < N - 1; i++) {
		cin >> str[i];

		int s_sub = abs((int)f_str.size() - (int)str[i].size());
		//cout << s_sub <<" ";
		if (s_sub > 1) continue; // 두 단어의 길이 차이 2 이상 

		for (int j = 0; j < 26; j++) p_arr[j] = 0;
		for (int j = 0; j < str[i].size(); j++) p_arr[(int)(str[i][j] - 'A')]++;

		int abs_sum = 0;
		/*cout << "p_arr : ";
		for (int j = 0; j < 26; j++) cout << p_arr[j]<<" ";
		cout << "\nf_arr : ";
		for (int j = 0; j < 26; j++) cout << f_arr[j] << " ";
		cout << '\n';*/
		for (int j = 0; j < 26; j++) abs_sum += abs(f_arr[j] - p_arr[j]);
		//cout << '\n';
		//cout << abs_sum << '\n';
		if (s_sub == 0 && abs_sum == 2) result++;
		if (s_sub == 1 && abs_sum == 1) result++;
		if (s_sub == 0 && abs_sum == 0) result++;
	}

	cout << result;

	return 0;
}