#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int Month[13] = { 0,0,31,59,90,120,151,181,212,243,273,304,334 };

int targetst = Month[3];
int targeted = Month[11] + 30 - 1;

struct Date {
	int start;
	int end;

	bool operator<(Date right) const {
		if (start < right.start) return true;
		if (start > right.start) return false;

		if (end < right.end) return true;
		if (end > right.end) return false;

		return false;
	}

};

vector<Date> v;

int cnt = 0;
int minCnt = 1e9;
void checkTime(int now) {

	if (v[now].end > targeted) {
		if (minCnt > cnt) {
			minCnt = cnt;
		}
		return;
	}

	int maxDate = 0;
	int next = -1;
	for (int i = now + 1; i < N; i++) {
		if (v[now].end >= v[i].start && maxDate < v[i].end) {
			maxDate = v[i].end;
			next = i;
		}
		else if (v[now].end < v[i].start) {
			break;
		}
	}


	if (next == -1) {
		return;
	}
	else {
		cnt++;
		checkTime(next);
	}

}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		int stm, std, edm, edd;
		cin >> stm >> std >> edm >> edd;
		int stDate = Month[stm] + std - 1;
		int edDate = Month[edm] + edd - 1;
		v.push_back({ stDate,edDate });
	}


	//cout << targetst << " " << targeted << endl<<endl;
	sort(v.begin(), v.end());

	/*for (int i = 0; i < N; i++) {
		cout << v[i].start << " " << v[i].end << endl;
	}*/
	int rN = 0;
	for (int i = 0; i < N; i++) {
		if (v[i].start <= targetst) {
			rN++;
		}
		else {
			break;
		}
	}

	int temp = 0;
	for (int i = 0; i < rN; i++) {
		if (i == 0 || v[i].end > temp) {
			cnt++;
			checkTime(i);
			cnt = 0;
			temp = v[i].end;
		}
	}

	if (minCnt == 1e9) {
		cout << 0;
	}
	else {
		cout << minCnt;
	}


	return 0;
}