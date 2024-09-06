#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int row;
	int col;
};

struct Node2 {
	int cnt;
	int num;
};

int map[51][51];
int i_map[51][51];
int arr[2501];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

int N, M;
Node sh;
int max_map = 0;
int last_idx = 0;
int tot_score = 0;

void indexed() {

	int rdr[4] = { 3,0,2,1 };
	int dir = 2;
	int cnt = 1;

	int num = 1;
	Node now = sh;
	int temp = 0;
	bool flag = true;
	while (flag) {
		
		if (temp == 2) {
			temp = 0;
			cnt++;
		}
		for (int k = 1; k <= cnt; k++) {
			int ner = now.row + dr[rdr[dir]];
			int nec = now.col + dc[rdr[dir]];
			
			
			if (ner < 0 || nec < 0 || ner >= N || nec >= N) {
				flag = false;
				break;
			}
			max_map++;
			arr[num] = map[ner][nec];
			if (arr[num] != 0) last_idx = num;
			i_map[ner][nec] = num++;

			now = { ner,nec };
		}
		dir = (dir + 1) % 4;
		temp += 1;

	}

}

void blizard() {
	int d, s;
	cin >> d >> s;

	for (int i = 1; i <= s; i++) {
		int ner = sh.row + dr[d - 1] * i;
		int nec = sh.col + dc[d - 1] * i;
		arr[i_map[ner][nec]] = 0;
	}
}

void con_boom() {

	int temp = 0;
	int cnt = 0;
	int r_cnt = 0;
	bool flag = false;
	for (int i = 1; i <= last_idx; i++) {
		if (arr[i] == 0 && i != last_idx) {
			cnt++;
			continue;
		}
		if (temp != arr[i]) {
			if (r_cnt > 3) {
				flag = true;
				for (int j = i - 1; j >= i - cnt; j--) {
					tot_score += arr[j];
					arr[j] = 0;
				}
			}
			temp = arr[i];
			cnt = 1;
			r_cnt = 1;
		}
		else {
			cnt++;
			r_cnt++;
		}
		if (i == last_idx && r_cnt > 3) {
			flag = true;
			for (int j = i; j > i - cnt; j--) {
				tot_score += arr[j];
				arr[j] = 0;
			}
		}
	}

	//for (int i = 1; i <= max_map; i++) cout << arr[i] << " ";
	//cout << "    :     " << tot_score << '\n';

	if (flag) con_boom();

}

void regen() {

	vector<Node2> v;

	int temp = 0;
	int cnt = 0;
	for (int i = 1; i <= last_idx; i++) {
		if (arr[i] == 0) {
			if (i == last_idx) v.push_back({ cnt, temp });
			continue;
		}
		if (temp != arr[i]) {
			if (temp != 0) v.push_back({ cnt, temp });
			temp = arr[i];
			cnt = 1;
		}
		else cnt++;

		if (i == last_idx) v.push_back({ cnt, temp });
	}

	int now = 1;
	for (int i = 0; i < v.size(); i++) {
		if (now >= max_map) break;
		arr[now] = v[i].cnt;
		now += 1;
		if (now >= max_map) break;
		arr[now] = v[i].num;
		now += 1;
	}
	if (now < last_idx) {
		for (int i = now; i <= last_idx; i++) arr[i] = 0;
	}
	last_idx = now - 1;
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	sh = { N / 2, N / 2 };

	indexed();

	//cout << '\n';
	//cout << max_map << '\n';

	//for (int i = 1; i <= max_map; i++) cout << arr[i] << " ";
	//cout << '\n';

	for (int i = 0; i < M; i++) {
		blizard();

		//for (int i = 1; i <= max_map; i++) cout << arr[i] << " ";
		//cout << '\n';
		//cout << last_idx<<'\n';
		con_boom();

		regen();

		//for (int i = 1; i <= max_map; i++) cout << arr[i] << " ";
		//cout << '\n';

	}

	//for (int i = 1; i <= max_map; i++) cout << arr[i] << " ";
	//cout << '\n';

	cout << tot_score;

	return 0;
}