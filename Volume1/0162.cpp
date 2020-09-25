#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int div_by(int x, int y) {
    while (x % y == 0) x = x / y;
    return x;
}

void Hamming(int m, int n, int* ans) {
    for (int i = m; i <= n; i++) {
        if(div_by(div_by(div_by(i, 2), 3), 5) == 1)
            (*ans)++;
    }
}

int main(void){
    while (true) {
        int m; cin >> m; if (m == 0) break;
        int n; cin >> n;
        int  ans = 0; 
        Hamming(m, n, &ans);
        cout << ans << endl;
    }
    return 0;
}
