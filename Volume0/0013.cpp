#include<iostream>
using namespace std;

int main(void)
{
	int a[128];
	int top = 0;
	for (int i = 0; i < 128; i++) { a[0] = 0; }

	for (int i = 0; i <= 9; i++) {
		int x;  cin >> x;
		if (x != 0) { a[top] = x; top++; }
		else {
			if (top == 0) {
				;
			}
			else{
				top--;
				cout << "out:" << a[top] << endl;
				a[top] = 0;
			}
		}
		
	}
	return 0;
}