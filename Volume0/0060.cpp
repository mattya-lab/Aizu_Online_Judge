#include<iostream>
#include<vector>
using namespace std;

#define vInt vector<int>
vInt deletecard(vInt a, int c1, int c2, int c3);

double isPossible(vInt a, int m) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (m + a[i] <= 20) { cnt++; }
    }
    return (double)cnt / a.size();
}

int main(void) {
	for (int z = 0; z < 3; z++) {
        vInt a;
        for (int i = 1; i <= 10; i++) { a.push_back(i); }
		
	    int c1, c2, c3; cin >> c1 >> c2 >> c3;
        a = deletecard(a, c1, c2, c3);

      
        double s = isPossible(a, c1 + c2);
        if (s * 100.0 >= 50.0) { cout << "YES" << endl; }
        else { cout << "NO" << endl; }
	}
	return 0;
}

vInt deletecard(vInt b, int c1, int c2, int c3) {
    int k = 0, cnt = 0, d[3] = { c1, c2, c3 };
    while (cnt < 3) {
        if (b[k] == d[cnt]) {
            b.erase(b.begin() + k);
            k = 0;
            cnt++;
        }
        else k++;
    }
    return b;
}