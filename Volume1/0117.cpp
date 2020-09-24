#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;
typedef long long ll;
#define INF (999)

typedef struct Route {
	int to, cost;

	Route(int s, int t) {
		to = s, cost = t;
	}
};

using vR = vector<Route>;
using vvR = vector<vR>;

int dijkstra(vvR vvr, int n, int s, int g) 
{
	vector<int> d(n);
	rep(i, n) { d[i] = INF; }
	d[s] = 0;

	priority_queue<p, vector<p>, greater<p>> que;
	que.push(p(0, s));
	while (!que.empty()) {
		p p1 = que.top();
		que.pop();
		int v = p1.second;
		if (d[v] < p1.first) { continue; }
		for (auto e : vvr[v]) {
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(p(d[e.to], e.to));
				
			}
		}

	}
	return d[g];
}

int main(void) 
{
	int n; cin >> n;
	int m; cin >> m;
	vvR vvr(n);
	rep(i, m) {
		int a, b, c, d;
		scanf("%d,%d,%d,%d", &a, &b, &c, &d);
		a--, b--;
		vvr[a].push_back(Route(b, c));
		vvr[b].push_back(Route(a, d));
	}
	int s, g, V, P;
	scanf("%d,%d,%d,%d", &s, &g, &V, &P);
	s--; g--;
	int ans = V - P - dijkstra(vvr, n, s, g) - dijkstra(vvr, n, g, s);
	cout << ans << endl;

	return 0;
}
