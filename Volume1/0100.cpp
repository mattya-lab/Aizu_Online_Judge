#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;

struct Info {
	int e;
	int sum;
};

int main(void) 
{
	while (true) {
		int n; cin >> n; if (n == 0) break;
		vector<Info> info(n);
		rep(i, n) {
			int e, p, q; cin >> e >> p >> q;
			bool f = true;
			rep(j, i) {
				if (info[j].e == e) {
					info[j].sum += p * q;
					f = false;
				}
			}

			if (f) {
				info[i].e = e;
				info[i].sum = p * q;
			}
		}
		bool f = true;
		rep(i, n) {
			if (info[i].sum >= 1000000) {
				printf("%d\n", info[i].e);
				f = false;
			}
		}
		if (f) {
			cout << "NA" << endl;
		}
	}
	return 0;
}