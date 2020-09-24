#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;
typedef long long ll;

struct Route {
	int num;
	struct Route* prev, * next;
};

void setRoute(struct Route** r);
void solve(struct Route** r, int s, int e) {
	vector<int> step;
	int cur_num = r[s]->num;

	while (true) {
		step.push_back(cur_num);

		if (cur_num == r[e]->num) { break; }
		else if (cur_num > r[e]->num) {
			if (cur_num == 0 || (6 <= cur_num && cur_num <= 9)) {
				cur_num = r[r[cur_num]->next->num]->num;
			}
			else {
				cur_num = r[r[cur_num]->prev->num]->num;
			}
		}
		else {
			cur_num = r[r[cur_num]->next->num]->num;
		}
	}

	rep(i, step.size())
		cout << step[i] << " ";
	printf("\n");
}


int main(void) {
	struct Route* r[10]; 
	setRoute(r);
	
	int n; cin >> n;
	rep(i, n) {
		int s, e; cin >> s >> e;
		solve(r, s, e);
	}
	return 0;
}

void setRoute(struct Route** r) {

	rep(i, 10) { r[i] = (Route*)malloc(sizeof(Route)); r[i]->num = i; }
	rep(i, 10) {
		if (i == 0 || (6 <= i && i < 9)) {
			r[i]->next = r[i + 1];
			r[i]->prev = NULL;
		}
		else if (i < 6) {
			r[i]->next = r[i + 1];
			r[i]->prev = r[i - 1];
		}
		else {
			r[9]->next = r[5];
			r[9]->prev = NULL;
		}
	}
}