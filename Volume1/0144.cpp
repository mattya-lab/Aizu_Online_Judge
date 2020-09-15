#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;

using vi = vector<int>;
using vvi = vector<vi>;

void print(vvi vvt, int n);

void findDestination(vvi vvt, int s, int next, int d, int v, int* ans, int depth)
{
	const int cost = 1;
	//cout << s << " " << next << " " << d << " " << v << endl;;

	if (v == 0) { return; }

	if(next == -1){
		rep(i, vvt[s].size()) {
			if (vvt[s][i] == d) {
				if ((*ans == 0) || cost + depth < (*ans)) { (*ans) = cost + depth;}
				return;
			}
		}
		rep(i, vvt[s].size()) {
			findDestination(vvt, s, vvt[s][i], d, v - 1, ans, depth + 1);
		}
	}
	else {
		rep(i, vvt[next].size()) {
			if (vvt[next][i] == d) {
				if ((*ans) == 0 || cost + depth < (*ans)) { (*ans) = cost + depth; }
				return;
			}
		}
		rep(i, vvt[next].size()) {
			findDestination(vvt, next, vvt[next][i], d, v - 1, ans,  depth + 1);
		}
	}
}

int main(void)
{
	int n; cin >> n;
	vvi vvt(n);
	rep(i, n) {
		int r, k; cin >> r >> k;
		rep(j, k) {
			int t;  cin >> t;
			t--; // adapt a index
			vvt[i].push_back(t);
		}
	}
	//print(vvt, n);

	int p; cin >> p;
	rep(i, p) {
		int s, d, v; cin >> s >> d >> v;
		s--, d--, v--; // adapt each index
		int ans = 0;
		int flag = 1;

		findDestination(vvt, s, -1, d, v, &ans,1);
		if (ans == 0) {
			cout << "NA" << endl;
		}
		else {
			cout << ans << endl;
		}
	}
	return 0;
}

void print(vvi vvt, int n) {
	rep(i, n) {
		cout << i << ": ";
		rep(j, vvt[i].size()) {
			cout << vvt[i][j] << " ";
		}
		cout << endl;
	}
}