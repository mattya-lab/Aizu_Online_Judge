#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;

struct frame {
	int p1;
	int p2;
	int p3;
	bool strike;
	bool spare;
};

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int calcframe(struct frame* frame);
void getAllFrame(struct frame* frame);


int main(void) {
	while (true) {
		int m; cin >> m; if (m == 0) { break; }
		vector<p> vp; // (id, score)
		struct frame frame[10]; 

		rep(i, m) {
			int id; cin >> id;
			getAllFrame(frame);
			int total_score = calcframe(frame);
			vp.push_back(make_pair(id, total_score));
		}
		sort(vp.begin(), vp.end(), compare);
		rep(i, m) {
			cout << vp[i].first << " " << vp[i].second << endl;
		}

	}
	return 0;
}

void getAllFrame(struct frame* frame)
{
	rep(i, 10) { frame[i].p1 = 0; frame[i].p2 = 0; frame[i].p3 = -1, frame[i].strike = false, frame[i].spare = false; }
	rep(i, 10) {
		bool f = true;
		cin >> frame[i].p1;
		if (frame[i].p1 == 10 && (i != 10 - 1)) {
			f = false;
			frame[i].strike = true;
		}

		if (f) {
			cin >> frame[i].p2;
			if ((frame[i].p1 + frame[i].p2) == 10 && (i != 10 - 1)) { frame[i].spare = true; }

			if (i == (10 - 1)) {
				if (frame[i].p1 == 10 || (frame[i].p1 + frame[i].p2) == 10) {  cin >> frame[i].p3; }
			}
		}
	}
}

int calcframe(struct frame* frame)
{
	int strike_cnt = 0;
	int total_score = 0;
	rep(i, 9) {
		if (frame[i].strike) { strike_cnt++; }
		else {
			if (strike_cnt > 0) {
				for (int j = strike_cnt; j > 0; j--) {
					switch (j) {
					case 1: total_score += 10 + (frame[i].p1 + frame[i].p2); break;
					case 2: total_score += 20 + (frame[i].p1); break;
					default: total_score += 30; break;
					}
				}
			}
			if (frame[i].spare) { total_score += (frame[i].p1 + frame[i].p2) + frame[i + 1].p1; }
			else { total_score += frame[i].p1 + frame[i].p2; }
			strike_cnt = 0;
		}
	}

	/** Round 10 **/
	if (strike_cnt > 0) {
		int frame10strikecnt = 0;
		if (frame[9].p1 == 10) {
			strike_cnt++;
			frame10strikecnt++;
			if (frame[9].p2 == 10) {
				strike_cnt++;
				frame10strikecnt++;
				if (frame[9].p3 == 10) {
					strike_cnt++;
					frame10strikecnt++;
				}
			}
		}

		for (int j = strike_cnt; j > 0; j--) {
			switch (j) {
			case 1: total_score += 10 + (frame[9].p1 + frame[9].p2); break;
			case 2: total_score += 20 + (frame[9].p1); break;
			default: total_score += 30; break;
			}
			if (j - 1 == frame10strikecnt) { break; }
		}
	}

	if (frame[9].p1 == 10) {
		total_score += 10 + frame[9].p2 + frame[9].p3;
	}
	else if (frame[9].p1 + frame[9].p2 == 10) {
		total_score += (frame[9].p1 + frame[9].p2) + frame[9].p3;
	}
	else {
		total_score += frame[9].p1 + frame[9].p2;
	}

	return total_score;
}