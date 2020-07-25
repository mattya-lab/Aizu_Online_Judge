#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++ )
#define N (1023)

struct circle {
	int num;
	struct circle *prev, *next;
};

struct circle *setcircle(int n);

int solve(struct circle* c, int n, int m) 
{
	int cycle = 0, cur = 0;
	int ans = 0, cnt = 0;
	while(true) {
		for (int cycle = 0; cycle < m - 1; cycle++) { c = c->next; }

		c->prev->next = c->next;
		c->next->prev = c->prev;
		cnt = cnt + 1;

		if (cnt == n) {
			ans = c->num;
			break;
		}
		c = c->next;
	}
	return ans;
}

int main(void) 
{
	while(true) {
		int n, m; cin >> n >> m; if (n == 0 && m == 0) { break; }
		struct circle* c;
		c  = setcircle(n);
		cout << solve(c, n, m) << endl;
		
		free(c);
	}
	return 0;
}

struct circle* setcircle(int n)
{
	struct circle* head, *p, *q;
	head = p = (struct circle*)malloc(sizeof(circle));
	head->num = 1;

	for (int i = 1; i < n; i++) {
		q = (struct circle*)malloc(sizeof(circle));
		q->num = i + 1;
		q->prev = p;
		p->next = q;
		p = q;
	}
	p->next = head;
	head->prev = p;
	return head;
	
}