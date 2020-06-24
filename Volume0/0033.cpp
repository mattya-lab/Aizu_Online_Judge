#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	int n; cin >> n;
	for (int z = 0; z < n; z++) {
		vector<int> a; for (int i = 0; i < 10; i++) { int t;  cin >> t; a.push_back(t); }
		vector<int> b;
		vector<int> c;
		bool flag = false;

		while (true)
		{
			if (a.empty()) { flag = true; break; }

			int t = a[0]; a.erase(a.begin());

			if (b.empty() && c.empty()) { b.push_back(t); }

			else if (c.empty()) {
				int l = t - b.back();
				if (t == 1) { c.push_back(t); }
				else if (l == 1) { b.push_back(t); }
				else if (l < 0) { c.push_back(t); }
				else {
					if (l < 3) { c.push_back(t); }
					else { b.push_back(t); }
				}
			}
			else {
				int l = t - b.back();
				int r = t - c.back();
				if (l < 0 && r < 0) break;
				else if (l == 1) { b.push_back(t); }
				else if (r == 1) { c.push_back(t); }

				else if (l > 0 && r < 0) { b.push_back(t); }
				else if (l < 0 && r > 0) { c.push_back(t); }

				else if (l < r) { b.push_back(t); }
				else if (l > r) { c.push_back(t); }
			}
		}

		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}