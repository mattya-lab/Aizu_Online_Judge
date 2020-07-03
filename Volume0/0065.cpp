#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

struct Trading {
	int num;
	int cnt;
	int month;

	Trading(int c, int d, int m) {
		num = c;
		cnt = d;
		month = m;
	}

	bool operator<(const Trading& another)const {
		return num < another.num;
	}
};


int main(void) 
{
	vector<Trading> p;
	int c, d;
	// Last Month.. 1
	rep(i, 3){
		(void)scanf("%d,%d", &c, &d);
		p.push_back(Trading(c, d, 1 ));
	}
	// This Month.. 2
	rep(i, 3){
		(void)scanf("%d,%d", &c, &d);
		p.push_back(Trading(c, d, 2));
	}
	sort(p.begin(), p.end());

	//rep(i, p.size()) cout << p[i].num << " " << p[i].cnt << " " << p[i].month << endl;
	
	int cnt = 1; bool m1 = false, m2 = false;

	for (int i = 0; i < p.size(); i++) {
		//cout << i << " : " << m1 << " " << m2 << " " << cnt << endl;
		if (i + 1 == p.size()) {
			if (m1 && m2) {
				cout << p[i].num << " " << cnt << endl;
			}
		}
		else if(p[i].num == p[i + 1].num ) {
			cnt++;
			if (p[i].month == 1) m1 = true;
			if (p[i].month == 2) m2 = true;
		}
		else {
			if (m1 || m2) {
				if (p[i].month == 1) m1 = true;
				if (p[i].month == 2) m2 = true;

				if (m1 && m2) {
					cout << p[i].num << " " << cnt << endl;
				}
			}
			m1 = false; m2 = false;
			cnt = 1;
		}

	}
	return 0;  
} 