#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define PI 3.14159265359

struct square {
	int cnt;
	bool vis;
};

void resetvisq(struct square** sq);
void print(struct square** sq);

void vistamp(struct square** sq, double s, double t) {
	sq[(int)t][(int)s].cnt++;
	sq[(int)t][(int)s].vis = true;

	rep(deg, 360) {
		double x = s + 1 * cos(deg * (PI / 180));
		double y = t + 1 * cos(deg * (PI / 180));

		if (x < 0.0 || y < 0.0 || x >= 10.0 || y >= 10.0)
			continue;

		if (!sq[(int)y][(int)x].vis){
			sq[(int)y][(int)x].cnt++;
			sq[(int)y][(int)x].vis = true;
		}
	}

}

int main(void) 
{	
	struct square* sq[10];
	rep(i, 10) sq[i] = (struct square*)malloc(sizeof(square) * 10);
	rep(i, 10) rep(j, 10) sq[i][j].cnt = 0;		
	while (true) {
		int n;  cin >> n; if (n == 0) { break; }
		rep(i, n) {
			resetvisq(&sq[0]);
			double s, t; (void)scanf("%lf,%lf", &s, &t);
			vistamp(&sq[0], s, t);
		}
		//print(&sq[0]);
		int ans = 0;
		rep(i, 10) rep(j, 10) ans = max(ans, sq[i][j].cnt);
		cout << ans << endl;
	}
	return 0;
}


void resetvisq(struct square **sq) {
	rep(i, 10) {
		rep(j, 10) {
			sq[i][j].vis = false;
		}
	}
}

void print(struct square **sq) {
	rep(i, 10) {
		rep(j, 10) {
			printf("%d ", sq[9 - i][j].cnt);
		}
		printf("\n");
	}

	printf("\n");

	rep(i, 10) {
		rep(j, 10) {
			printf("%d ", sq[9 - i][j].vis);
		}
		printf("\n");
	}
	printf("\n");
}
