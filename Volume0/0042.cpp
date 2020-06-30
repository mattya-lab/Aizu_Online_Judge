#include<iostream>
#include<vector>
using namespace std;

int max_v = 0, max_w = 0;

void Combination(vector<pair<int, int>> pairs, int w, int n, int s, int t, int i)
{
	s += pairs[i].first;
	t += pairs[i].second;

	if (t > w) { return; }

	if (s > max_v && t < w) {
		max_v = s;
		max_w = t;
	}
	//cout << s << " " << t << endl;
	for (int k = i + 1; k < n; k++) { Combination(pairs, w, n, s, t, k); }

}

int main(void) 
{
	int Case = 1;
	while (true) {
		int w; cin >> w; if (w == 0) { break; }
		int n;  cin >> n;
		vector<pair<int, int>> pairs(n);
		for (int i = 0; i < n; i++) {
			int v, w;
			(void)scanf_s("%d,%d", &v, &w);
			pairs[i] = make_pair(v, w);
		}

		for (int i = 0; i < n; i++) { Combination(pairs, w, n, 0, 0, i); }

		cout << "Case " << Case << ":" << endl;
		cout << max_v << endl;
		cout << max_w << endl;

		Case++;
	}
	return 0;
}
