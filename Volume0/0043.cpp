#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define vInt vector<int>

bool c[10];
bool flag;

vInt reset(vInt b);
void countnum9(vInt b,int num9[]);
void print(vInt b, int num9[], int i);
vInt del3card(vInt b, int val);
vInt del2pair(vInt b, int val);
vInt delEachcard(vInt b, int l, int m, int r);

void puzzle(const vInt b, int num9[], int i, int l, int m, int r)
{
    if (flag) return;

    vInt copyb;
    rep(j, b.size()) { copyb.push_back(b[j]); }
    countnum9(b, num9);

    bool f0 = false;
    if ((num9[1] % 3 == 1 && num9[2] == 0) || (num9[8] == 0 && num9[9] % 3 == 1)) { f0 = true; }
    else if ((num9[1] == 2 && num9[2] == 0) || (num9[8] == 0 && num9[9] == 2)) { f0 = true; }
    else if (num9[1] == 1 && num9[2] == 1 && num9[3] == 0) { f0 = true; }
    else if (num9[7] == 0 && num9[8] == 1 && num9[9] == 1) { f0 = true; }
    else if (num9[1] == 2 && num9[2] == 2 && num9[3] == 0) { f0 = true; }
    else if (num9[7] == 0 && num9[8] == 2 && num9[9] == 2) { f0 = true; }
    else if (num9[1] == 2 && num9[2] == 1 && num9[3] == 0) { f0 = true; }
    else if (num9[7] == 0 && num9[8] == 1 && num9[9] == 2) { f0 = true; }
    else if (num9[l] == 0 && num9[m] == 1 && num9[r] == 0) { f0 = true; }
    else if (num9[l] == 0 && num9[m] % 3 == 1 && num9[r] % 3 == 1 && num9[r + 1] == 0 && r <= 8) { f0 = true; }
    else if (num9[l] == 0 && num9[m] == 1 && num9[r] == 2 && num9[r + 1] == 0 && r <= 8) { f0 = true; }
    else if (num9[l] == 0 && num9[m] == 2 && num9[r] == 1 && num9[r + 1] == 0 && r <= 8) { f0 = true; }
    
    if (f0) { return ; }

    if (l == 0 && m == 0 && r == 0) {
        rep(j, 10) { if (num9[j] == 5) { return; } }
        for (int j = 1; j <= 7; j++) { puzzle(copyb, num9, i, j, j + 1, j + 2); }
    }
    else {

        if (num9[l] >= 1 && num9[m] >= 1 && num9[r] >= 1) { copyb = delEachcard(copyb, l, m, r); }
        
        if (num9[1] >= 3 && num9[2] == 0) { copyb = del3card(copyb, 1); }
        else if (num9[8] == 0 && num9[9] >= 3) { copyb = del3card(copyb, 9); }
        else if (num9[1] >= 3 && num9[2] == 1 && num9[3] == 0) { copyb = del3card(copyb, 1); }
        else if (num9[7] == 0 && num9[8] == 1 && num9[9] >= 3) { copyb = del3card(copyb, 9); }
        else if (num9[1] >= 3 && num9[2] == 2 && num9[3] == 0) { copyb = del3card(copyb, 1); }
        else if (num9[7] == 0 && num9[8] == 2 && num9[9] >= 3) { copyb = del3card(copyb, 9); }

        else if (num9[l] == 0 && num9[m] >= 3 && num9[r] == 0) { copyb = del3card(copyb, m); }
        else if (num9[l] >= 3 && num9[m] >= 3 && num9[r] == 0) { copyb = del3card(copyb, m); }
        else if (num9[l] == 0 && num9[m] >= 3 && num9[r] >= 3) { copyb = del3card(copyb, m); }
        
        else if (num9[l] == 0 && num9[m] == 3 && num9[r] == 2) { copyb = del3card(copyb, m); }
        else if (num9[l] == 2 && num9[m] == 3 && num9[r] == 0) { copyb = del3card(copyb, m); }
        

        if (copyb.size() == b.size()) { return; }
        countnum9(copyb, num9);
        //if (!flag) { print(copyb, num9, i); }

        bool f2 = true;
        int idx = 1, cnt = 0, p = 0;;
        while (f2 && idx < 10) {
            if (num9[idx] == 0) { idx++; }
            else if (num9[idx] == 2 && cnt == 0) { cnt++; p = idx; idx++; }
            else { f2 = false; }
        }

        if (f2 && cnt == 1) { copyb = del2pair(copyb, p); flag = true; }

        puzzle(copyb, num9, i, 1, 2, 3);
        puzzle(copyb, num9, i, 2, 3, 4);
        puzzle(copyb, num9, i, 3, 4, 5);
        puzzle(copyb, num9, i, 4, 5, 6);
        puzzle(copyb, num9, i, 5, 6, 7);
        puzzle(copyb, num9, i, 6, 7, 8);
        puzzle(copyb, num9, i, 7, 8, 9);
    }
}


int main(void)
{
    rep(z, 6) {
        char s[13 + 1]; cin >> s;
        int a[13]; rep(i, 13) { a[i] = s[i] - '0'; }
        rep(i, 10){ c[i] = false; }

        vInt b;
        bool f1 = false;
        for (int i = 1; i <= 9; i++) {
            flag = false;
            b.push_back(i);

            rep(j, 13) { b.push_back(a[j]); }
            sort(b.begin(), b.end());

            int num9[10];
            countnum9(b, num9);
            puzzle(b, num9, i, 0, 0, 0);

            c[i] = flag;
            b = reset(b); 
            if (c[i]) { cout << i << " "; f1 = true; }
        }
        if (!f1) cout << "0";
        cout << endl;
    }
    return 0;
}

vInt del3card(vInt b, int val) {
    int k = 0, cnt = 0, d[3] = { val, val, val };
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

vInt del2pair(vInt b, int val) {
    int k = 0, cnt = 0, d[2] = { val, val };
    while (cnt < 2) {
        if (b[k] == d[cnt]) {
            b.erase(b.begin() + k);
            k = 0;
            cnt++;
        }
        else k++;
    }
    return b;
}

vInt delEachcard(vInt b, int l, int m, int r) {
    int k = 0, cnt = 0, d[3] = { l, m, r };
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

vInt reset(vInt b) {
    int size = b.size();
    for (int l = 0; l < size; l++) { b.erase(b.begin()); }
    return b;
}

void countnum9(vInt b, int num9[]) {
    rep(j, 10) { num9[j] = 0; }
    rep(j, b.size()) { num9[b[j]]++; }
}

void print(vInt b, int num9[], int i) {
    printf("----------------------------\n");
    printf("%d: ", i);
    rep(l, b.size()) { printf("%d ", b[l]); }
    printf("\n");
    printf("%d: ", i);
    for (int j = 1; j <= 9; j++) { printf("%d ", num9[j]); }
    printf("\n");
    printf("----------------------------\n");
}
