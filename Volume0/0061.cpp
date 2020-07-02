#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

bool sortbysec(const pair<int, int> & a, const pair<int, int> & b) {
	return a.second > b.second;
}

int main(void)
{
	vector<pair<int, int>> t;
	while (true) {
		int u, v; (void)scanf("%d,%d", &u, &v);
		if (u == 0 && v == 0) { break; }
		t.push_back(make_pair(u, v));
	}
	sort(t.begin(), t.end(), sortbysec);
	
	vector<int> t_rank(t.size());
	int rank = 1;
	t_rank[0] = 1;
	for (int i = 1; i < t.size(); i++) {
		if (t[i - 1].second == t[i].second) { t_rank[i] = rank; }
		else {
			rank++;
			t_rank[i] = rank;
		}
	}

	//for (int i = 0; i < t.size(); i++) cout << t[i].first << " " << t[i].second << " " << t_rank[i] << endl;

	int n = 4;
	for (int z = 0; z < n; z++) {
		int q; cin >> q;
		for (int i = 0; i < t.size(); i++) {
			if (q == t[i].first) { cout << t_rank[i] << endl; break; }
		}
	}
	return 0;
}