#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;
typedef long long ll;
#define INF (999)

typedef struct Waiter {
	int t;
	int wt;
};
using vw = vector<Waiter>;

void combination(const vw que, int rear, const vw w, const vector<bool> vis, int idx, int n, int *ans) {
	if (vis[idx]) return;

	vector<bool> cvis(n);
	rep(i, n) cvis[i] = vis[i];
	cvis[idx] = true;

	vw cque(n);
	rep(i, n) {
		cque[i].t = que[i].t, cque[i].wt = que[i].wt;
	}
	cque[rear].t = w[idx].t;
	int sum = 0;
	rep(i, rear) { sum += cque[i].t; }
	cque[rear].wt = sum;

	bool f = true;
	rep(i, n) { if (!cvis[i]) f = false; }
	if (f) {
		int sum = 0;
		rep(i, n) sum += cque[i].wt;
		(*ans) = min(*ans, sum);
		return;
	}

	rep(i, n) { combination(cque, rear + 1, w, cvis, i, n, ans); } 
}

void calcMinTime(const vw w, int idx, int n, int *ans){
	vector<bool> vis(n, false);
	vis[idx] = true;
	vw que(n);
	rep(i, n) { que[i].t = -1, que[i].wt = -1; }
	int rear = 0;
	que[rear].t = w[idx].t, que[rear].wt = 0;
	rep(i, n) combination(que, rear + 1, w, vis, i, n, ans);
}

int main(void)
{
	while (true) {
		int n; cin >> n; if (n == 0) break;
		vw w(n);
		int sum = 0;
		rep(i, n) {
			int t; cin >> t;
			w[i].t = t, w[i].wt = sum;
			sum += t;
		}
		int ans = 0; 
		rep(i, n) { ans += w[i].wt; }
		rep(i, n) {
			calcMinTime(w, i, n, &ans);
		}
		cout << ans << endl;
	}
	return 0;
}