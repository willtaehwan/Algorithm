#include <iostream>
#include <unordered_map>
using namespace std;

int numMap[21][21] = { 0, };
int N;

int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };

struct prefer {
	int pref[4];
};

unordered_map<int, prefer> pre;

void setSeat(int num) {
	int tar = 0;
	int tac = 0;
	int maxScore = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (numMap[i][j] != 0) continue;

			int score = 9999 - (i * 100) - j;

			for (int k = 0; k < 4; k++) {
				int ner = i + dr[k];
				int nec = j + dc[k];

				if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;
				if (numMap[ner][nec] == 0) score += 10000;
				for (int l = 0; l < 4; l++) {
					if (numMap[ner][nec] == pre[num].pref[l]) score += 100000;
				}
			}
			
			if (maxScore < score) {
				maxScore = score;
				tar = i;
				tac = j;
			}
		}
	}
	//cout << tar << " " << tac << endl;
	numMap[tar][tac] = num;
	
	return;
}

int satisfactionSurvey() {
	int result = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int score = 0;
			for (int k = 0; k < 4; k++) {
				int ner = i + dr[k];
				int nec = j + dc[k];

				if (ner < 0 || nec < 0 || ner >= N || nec >= N) continue;
				for (int l = 0; l < 4; l++) {
					if (numMap[ner][nec] == pre[numMap[i][j]].pref[l]) score++;
				}
			}
			if (score == 0) continue;
			else {
				int f_score = 1;
				for (int k = 0; k < score - 1; k++) {
					f_score *= 10;
				}
				//cout << numMap[i][j] << " ";
				//cout << f_score<<endl;
				result += f_score;
			}
		}
	}

	return result;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N*N; i++) {
		int num, a, b, c, d;
		cin >> num >> a >> b >> c >> d;
		pre.insert({num,{a,b,c,d}});
		setSeat(num);
	}
	/*cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << numMap[i][j]<<" ";
		}
		cout << endl;
	}*/

	int result = satisfactionSurvey();
	cout << result;

	return 0;
}