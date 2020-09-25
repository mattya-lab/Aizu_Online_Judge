#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;
typedef long long ll;

using vi = vector<int>;
using vvi = vector<vi>;

bool checkPArray(vvi s, vi si, int cnt, int n);
void print(vvi s);
vi setNextSiArray(vvi s, vector<p> ci, int cnt, int n);
vector<p> FrequencyCount(vi s);

int main(void)
{
	while (true)
	{
		int n;	cin >> n; if (n == 0) { break; }
		vvi s;
		vi si(n); rep(i, n) cin >> si[i];
		bool f = true;
		int cnt = 0;
		while (f)
		{
			s.push_back(si);
			vector<p> ci = FrequencyCount(si);
			si = setNextSiArray(s, ci, cnt, n);
			f = checkPArray(s, si, cnt, n);
			cnt++;
		}
		cout << cnt - 1 << endl;
		rep(i, n) { cout << si[i] << " "; }
		cout << endl;
	}
	return 0;
}

bool checkPArray(vvi s, vi si, int cnt, int n) {
	int k = 0;
	rep(i, si.size()) {
		if (s[cnt][i] == si[i]) { k++; }
		if (k == n) { return false; }
	}
	return true;
}

vi setNextSiArray(vvi s, vector<p> ci, int cnt, int n) {
	vi si(n);
	rep(i, n) {
		rep(j, ci.size()) {
			if (s[cnt][i] == ci[j].first)
				si[i] = ci[j].second;
		}
	}
	return si;
}

vector<p> FrequencyCount(vi si)
{
	vector<p> fs;
	rep(i, si.size()) {
		bool f = true;
		rep(j, fs.size()) {
			if (si[i] == fs[j].first) {
				fs[j].second++;
				f = false;
			}
		}
		if (f) {
			fs.push_back(make_pair(si[i], 1));
		}
	}
	return fs;
}

void print(vvi s) {
	rep(i, s.size()) {
		rep(j, s[i].size())
			cout << s[i][j] << " ";
		printf("\n");
	}
	printf("-----------------------\n");
}