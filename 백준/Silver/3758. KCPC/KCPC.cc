#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct team {
	int tr;
	int time;
};

struct res {
	int idx;
	int tot;
	int la_tr;
	int la_ti;

	bool operator<(res right) const {
		if (tot > right.tot) return true;
		if (tot < right.tot) return false;

		if (la_tr < right.la_tr) return true;
		if (la_tr > right.la_tr) return false;

		if (la_ti < right.la_ti) return true;
		
		return false;
	}
};

int N, K, ID, M;
int sc[102][102] = { 0, };
team te[102];

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		cin >> N >> K >> ID >> M;

		for (int i = 1; i <= N; i++) {
			te[i] = { 0,0 };
			for (int j = 1; j <= K; j++) {
				sc[i][j] = 0;
			}
		}


		for (int i = 0; i < M; i++) {
			int id, num, score;
			cin >> id >> num >> score;
			te[id].tr++;
			te[id].time = i;
			sc[id][num] = max(sc[id][num], score);
		}
		vector<res> v;
		for (int i = 1; i <= N; i++) {
			int tot_score = 0;
			for (int j = 1; j <= K; j++) tot_score += sc[i][j];
			v.push_back({i, tot_score, te[i].tr, te[i].time });
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {

			//cout <<"   "<<v[i].idx<<" " << v[i].tot << " " << v[i].la_tr << " " << v[i].la_ti << '\n';

			if (v[i].idx == ID) {
				cout << i + 1 << "\n";
				break;
			}
		}
	}

	return 0;
}