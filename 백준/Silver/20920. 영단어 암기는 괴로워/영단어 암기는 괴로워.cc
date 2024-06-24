#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
unordered_map<string, int> m;


bool comp(pair<string,int>& a, pair<string, int>& b) {
	if (a.first.size() == b.first.size() && a.second == b.second) return a < b; // 빈도와 길이가 같다면 알파벳 순
	else if (a.second == b.second) return a.first.size() > b.first.size(); // 빈도가 같다면 길이가 긴 단어
	return a.second > b.second; // 자주 나오는 단어
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str.size() >= M) m[str]++;
	}
	vector<pair<string,int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), comp);

	for (auto p : v) cout << p.first << '\n';

	return 0;
}