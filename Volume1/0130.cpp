#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
#define INF (999)

#define SIZE (255)

typedef struct Block {
	char c;
	Block *prev, *next;
};

Block * mazeTrain(char *s) {
	int len = 0;
	Block* top, *p;
	top = (Block*)malloc(sizeof(Block));
	top->c = s[len];
	top->prev = NULL, top->next = NULL;
	len++;

	p = top;
	while (true) {
		if (s[len] == '\0') { break; }

		struct Block *b;
		b = (Block*)malloc(sizeof(Block));
		b->c = s[len + 2];
		b->prev = NULL, b->next = NULL;

		if (s[len] == '-' && s[len + 1] == '>') {
			if (p->next == NULL) { 
				b->prev = p;
				p->next = b;
			}
			p = p->next;
		}
		else { // "<-"
			if (p->prev == NULL) { 
				b->next = p;
				p->prev = b;
				top = p->prev;
			}
			p = p->prev;
		}
		len += 3;
	}

	return top;
}

int main(void) {
	int n; cin >> n;
	rep(i, n) {
		char s[SIZE] = " "; cin >> s;
		Block* b = mazeTrain(s);

		while(b != NULL){
			cout << b->c; 
			b = b->next;
		}
		printf("\n");
	}
	return 0;
}