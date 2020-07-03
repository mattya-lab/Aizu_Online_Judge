#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

void swap(int* x, int* y);
int  findStarline(vector<pair<int, int>> pairs, vector<string> s, int n);

void addWidthline(vector<pair<int, int>> pairs, vector<string> s, int m, int n, int point, int *row, int *col)
{
	bool f = false;
	rep(i, s.size()) {
		if (f) { return; }
 		int sum = 0;
		rep(j, n - 1) { sum += s[i][j] - '0'; }
		if (sum == int(n / 2)) { cout << i + 1 << endl; continue; }
		
		rep(j, (n - 1) - 1) {
			if (s[i][j] == '1' && s[i][j + 1] == '0') {
				for (int k = j + 2; k < n - 1; k++) {
					bool f1 = false;
					if (s[i][k] == '0') { s[i][k] = '1'; f1 = true; }

					int point = findStarline(pairs, s, n);
					if (point == m && !f) {
						*row = i + 1;
						*col = k + 1;
						f = true;
					}
					if (f1) s[i][k] = '0';
				}
			}
		}
	}
}

int main(void)
{
	int n; cin >> n;
	int m; cin >> m;
	int star; cin >> star;
	int d; cin >> d;
	vector<pair<int, int>> pairs(n);

	rep(i, n) {
		pairs[i].first = i + 1;
		if (pairs[i].first == star) { pairs[i].second = 1; }
		else { pairs[i].second = 0; }
	}

	vector<string> s;
	rep(i, d){
		char wideline[4 + 1] = ""; cin >> wideline;
		if (strcmp(wideline, "0") == 0) { break; }
		s.push_back(wideline);
	}

	int point = findStarline(pairs, s, n);
	if (point == m) { cout << "0" << endl; return 0; }

	int row = 0, col = 0;
	addWidthline(pairs, s, m, n, point, &row, &col);
	cout << row << " " << col << endl;

	return 0;
}


int  findStarline(vector<pair<int, int>> pairs, vector<string> s, int n)
{
	rep(i, s.size()) {
		rep(j, n - 1) {
			if (s[i][j] == '1') { swap(pairs[j].first, pairs[j + 1].first); }
		}
	}
	int point = 0;
	rep(i, n) { if (pairs[i].second == 1) { point = pairs[i].first; } }

	return point;
}

void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}