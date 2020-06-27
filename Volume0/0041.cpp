#include<iostream>
using namespace std;

int p0, p1, p2, p3;
char q0, q1, q2;
int r;

int calc(int a, char c, int b) {
	switch (c) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	}
}

void equal10(int s, int t, int u, int v, char x, char y, char z)
{
	if (x == ' ' && y == ' ' && z == ' ') {
		equal10(s, t, u, v, '+', '+', '+');
		equal10(s, t, u, v, '+', '+', '-');
		equal10(s, t, u, v, '+', '+', '*');
		equal10(s, t, u, v, '+', '-', '+');
		equal10(s, t, u, v, '+', '-', '+');
		equal10(s, t, u, v, '+', '-', '*');
		equal10(s, t, u, v, '+', '*', '+');
		equal10(s, t, u, v, '+', '*', '-');
		equal10(s, t, u, v, '+', '*', '*');

		equal10(s, t, u, v, '-', '+', '+');
		equal10(s, t, u, v, '-', '+', '-');
		equal10(s, t, u, v, '-', '+', '*');
		equal10(s, t, u, v, '-', '-', '+');
		equal10(s, t, u, v, '-', '-', '-');
		equal10(s, t, u, v, '-', '-', '*');
		equal10(s, t, u, v, '-', '*', '+');
		equal10(s, t, u, v, '-', '*', '-');
		equal10(s, t, u, v, '-', '+', '+');

		equal10(s, t, u, v, '*', '+', '+');
		equal10(s, t, u, v, '*', '+', '-');
		equal10(s, t, u, v, '*', '+', '*');
		equal10(s, t, u, v, '*', '-', '+');
		equal10(s, t, u, v, '*', '-', '-');
		equal10(s, t, u, v, '*', '-', '*');
		equal10(s, t, u, v, '*', '*', '+');
		equal10(s, t, u, v, '*', '*', '-');
		equal10(s, t, u, v, '*', '*', '*');
	}
	else {
		int sum;
		bool flag = false;

		sum = calc(calc(s, x, t), y, calc(u, z, v));
		if (sum == 10) { flag = true, r = 0; }

		sum = calc(calc(s, x, calc(t, y, u)), z, v);
		if (sum == 10) { flag = true, r = 1; }

		sum = calc(s, x, calc(calc(t, y, u), z, v));
		if (sum == 10) { flag = true, r = 2; }
		
		sum = calc(calc(calc(s, x, t), y, u), z, v);
		if (sum == 10) { flag = true, r = 3; }
		
		sum = calc(s, x, calc(t, y, calc(u, z, v)));
		if (sum == 10) { flag = true, r = 4; }

		if (flag) {
			p0 = s, p1 = t, p2 = u, p3 = v;
			q0 = x, q1 = y, q2 = z;
		}
	}
}

int main(void) {
	while (true) {
		p0 = 0, p1 = 0, p2 = 0, p3 = 0;
		q0 = ' ', q1 = ' ', q2 = ' ';
		r = -1;

		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0) { break; }

		equal10(a, b, c, d, ' ', ' ', ' ');
		equal10(a, b, d, c, ' ', ' ', ' ');
		equal10(a, c, d, b, ' ', ' ', ' ');
		equal10(a, c, b, d, ' ', ' ', ' ');
		equal10(a, d, b, c, ' ', ' ', ' ');
		equal10(a, d, c, b, ' ', ' ', ' ');

		equal10(b, a, c, d, ' ', ' ', ' ');
		equal10(b, a, d, c, ' ', ' ', ' ');
		equal10(b, c, d, a, ' ', ' ', ' ');
		equal10(b, c, a, d, ' ', ' ', ' ');
		equal10(b, d, a, c, ' ', ' ', ' ');
		equal10(b, d, c, a, ' ', ' ', ' ');

		equal10(c, a, b, d, ' ', ' ', ' ');
		equal10(c, a, d, b, ' ', ' ', ' ');
		equal10(c, b, d, a, ' ', ' ', ' ');
		equal10(c, b, a, d, ' ', ' ', ' ');
		equal10(c, d, a, b, ' ', ' ', ' ');
		equal10(c, d, b, a, ' ', ' ', ' ');

		equal10(d, a, c, b, ' ', ' ', ' ');
		equal10(d, a, b, c, ' ', ' ', ' ');
		equal10(d, c, b, a, ' ', ' ', ' ');
		equal10(d, c, a, b, ' ', ' ', ' ');
		equal10(d, b, a, c, ' ', ' ', ' ');
		equal10(d, b, c, a, ' ', ' ', ' ');

		switch (r) {
		case 0: printf("((%d %c %d) %c (%d %c %d))\n", p0, q0, p1, q1, p2, q2, p3); break;
		case 1: printf("((%d %c (%d %c %d)) %c %d)\n", p0, q0, p1, q1, p2, q2, p3); break;
		case 2: printf("(%d %c ((%d %c %d) %c %d))\n", p0, q0, p1, q1, p2, q2, p3); break;
		case 3: printf("(((%d %c %d) %c %d) %c %d))\n", p0, q0, p1, q1, p2, q2, p3); break;
		case 4: printf("(%d %c ( %d %c (%d %c %d)))\n", p0, q0, p1, q1, p2, q2, p3); break;
		default: printf("0\n"); break;
		}
	}
	return 0;
}