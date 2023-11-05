#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k;

int map[101][101] = { 0, };

int rsize = 3;
int csize = 3;

struct sortArray {
	int num;
	int cnt;
};

bool cmp(sortArray left, sortArray right) {
	if (left.cnt > right.cnt) return false;
	if (left.cnt < right.cnt) return true;
	if (left.num > right.num) return false;
	if (left.num < right.num) return true;

	return false;
};



void sortedArray_R() {

	
	int tempSize = 0;
	for (int i = 0; i < rsize; i++) {
		vector<int> v;
		int DAT[101] = { 0, };
		int visited[101] = { 0, };
		for (int j = 0; j < csize; j++) {
			int temp = map[i][j];
			map[i][j] = 0;
			if (temp == 0) continue;
			DAT[temp]++;
			if (visited[temp] != 0) continue;
			else {
				visited[temp] = 1;
				//cout << temp << " ";
				v.push_back(temp);
			}
		}
		//cout << endl;
		//cout << "v size = " << v.size() << endl;
		vector<sortArray> v2;
		for (int j = 0; j < v.size(); j++) {
			v2.push_back({ v[j], DAT[v[j]] });
		}
		
		sort(v2.begin(), v2.end(), cmp);
		//cout << "v2 size = " << v2.size() << endl;
		for (int j = 0; j < v2.size() * 2; j += 2) {
			map[i][j] = v2[j / 2].num;
			map[i][j + 1] = v2[j / 2].cnt;
		}

		if (tempSize < v2.size() * 2) {
			tempSize = v2.size() * 2;
		}
		//cout << "sdfsdofksdof" << endl;
	}
	csize = tempSize;
}

void sortedArray_C() {

	int tempSize = 0;
	for (int i = 0; i < csize; i++) {
		vector<int> v;
		int DAT[101] = { 0, };
		int visited[101] = { 0, };
		for (int j = 0; j < rsize; j++) {
			int temp = map[j][i];
			map[j][i] = 0;
			if (temp == 0) continue;
			DAT[temp]++;
			if (visited[temp] != 0) continue;
			else {
				visited[temp] = 1;
				//cout << temp << " ";
				v.push_back(temp);
			}
		}
		//cout << endl;
		//cout << "v size = " << v.size() << endl;
		vector<sortArray> v2;
		for (int j = 0; j < v.size(); j++) {
			v2.push_back({ v[j], DAT[v[j]] });
		}

		sort(v2.begin(), v2.end(), cmp);
		//cout << "v2 size = " << v2.size() << endl;
		for (int j = 0; j < v2.size() * 2; j += 2) {
			map[j][i] = v2[j / 2].num;
			map[j+1][i] = v2[j / 2].cnt;
		}

		if (tempSize < v2.size() * 2) {
			tempSize = v2.size() * 2;
		}
		//cout << "sdfsdofksdof" << endl;
	}
	rsize = tempSize;

}



int main() {

	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	int timeCheck = 0;
	int result = -1;
	//cout << endl;
	while (timeCheck <= 100) {

		if (map[r - 1][c - 1] == k) {
			result = timeCheck;
			break;
		}

		if (rsize >= csize) sortedArray_R();
		else sortedArray_C();

		/*cout << endl;
		for (int i = 0; i < rsize; i++) {
			for (int j = 0; j < csize; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
		
		timeCheck++;
	}

	cout << result;

	return 0;

}