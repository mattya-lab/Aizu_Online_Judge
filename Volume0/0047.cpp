#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(void)
{
	vector<pair<char, int>> cup(3);
	cup[0] = make_pair('A', 1);
	cup[1] = make_pair('B', 0);
	cup[2] = make_pair('C', 0);

	for (int i = 0; i < 5; i++) {
		char x = ' ', y = ' '; cin >> x >> y; 
		int s = 0, t = 0;
		for (int j = 0; j < 3; j++) {
			if (cup[j].first == x) { s = j; }
			else if (cup[j].first == y) { t = j; }
		}
	
		char tmp;
		tmp = cup[s].first;
		cup[s].first = cup[t].first;
		cup[t].first = tmp; 
	}

	cout << cup[0].first << endl;

	return 0;
}