#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;
typedef long long ll;

struct Record {
	int p;
	double t;

	bool operator<(const Record& another)const {
		return t < another.t;
	}
};

int main(void)
{
	int idx = 0;
	vector<Record> w(8);
	Record st, nd, rd[3], temp;
	rep(i, 3) {
		st.p = 0, st.t = 999, nd.p = 0, nd.t = 999, rd[i].p = 0, rd[i].t = 999;
		rep(j, 8) {
			int p; cin >> p;
			double t; cin >> t;

			if (st.t > t) {
				temp.p = st.p, temp.t = st.t;
				st.p = p; st.t = t;
				p = temp.p; t = temp.t;
			}
			if (nd.t > t) {
				temp.p = nd.p, temp.t = nd.t;
				nd.p = p, nd.t = t;
				p = temp.p, t = temp.t;
			}
			if (rd[i].t > t) {
				temp.p = rd[i].p, temp.t = rd[i].t;
				rd[i].p = p, rd[i].t = t;
				p = temp.p, t = temp.t;
			}
		}
		w[idx].p = st.p, w[idx].t =st.t;
		w[idx + 1].p = nd.p, w[idx + 1].t = nd.t;
		idx = idx + 2;
	}

	sort(rd, rd + 3);
	w[idx].p = rd[0].p, w[idx].t = rd[0].t;
	w[idx + 1].p = rd[1].p, w[idx + 1].t = rd[1].t;
	idx += 2;

	rep(i, idx) {
		cout << w[i].p << " " << w[i].t << endl;
	}
	return 0;
}