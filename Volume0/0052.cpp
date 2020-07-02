#include<iostream>
using namespace std;

int main(void)
{
	while (1) {
		int n; cin >> n; if (n == 0) { break; }

		int cnt2 = 0, cnt5 = 0;
		for(int i = 1; i <= n; i++){
			int k = i;
			while(k % 2 == 0){
				k = k / 2;
				cnt2++;
			}
			while (k % 5 == 0) {
				k = k / 5;
				cnt5++;
			}
		}
		cout << cnt5 << endl;
	}
	return 0;
}