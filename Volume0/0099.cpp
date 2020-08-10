#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;

#define vecInt vector<int>

int main(void) {
	int n, q; cin >> n >> q;
	vector<p> p(q);

	rep(i, q) {
		int a, v;
		cin >> a >> v;
		bool f = true;
		rep(j, i){
		if (a == p[j].first) {
				p[j].second += v;
				f = false;
			}
		}

		if (f) {
			p[i].first = a;
			p[i].second = v;
		}

		int max_a = p[0].first;
		int max_v = p[0].second;;
		for (int j = 1; j <= i; j++) {
			if (p[j].second > max_v) {
				max_a = p[j].first;
				max_v = p[j].second;
			}
		}
		cout << max_a << " " << max_v << endl;;
	}

	return 0;
}