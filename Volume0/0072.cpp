#includeb<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;

#define vecInt vector<int>

struct UnionFind {
	vecInt parent;
	vecInt sizes;

	UnionFind(int n) : parent(n), sizes(n, 1) {
		rep(i, n) parent[i] = i;
	}

	int find(int x) { return (x == parent[x]) ? x : find(parent[x]); }

	void unite(int x, int y) {
		x = find(x);
		y = find(y);

		if (x == y) return;
		if (sizes[x] < sizes[y]) swap(x, y);

		parent[y] = x;
		sizes[x] += sizes[y];
	}

	bool same(int x, int y) { return find(x) == find(y); }

	int size(int x) { return sizes[find(x)]; }
};

struct Edge {
	int from;
	int to;
	int cost;

	bool operator<(const Edge& p) const {
		return cost < p.cost;
	}
};

#define vecEdge vector<Edge>

struct Graph {
	int n;
	vecEdge es;

	int kruskal() {
		sort(es.begin(), es.end());

		struct UnionFind uf(n);
		int min_cost = 0;

		rep(ei, es.size()) {
			Edge& e = es[ei];
			if (!uf.same(e.from, e.to)) {
				min_cost += e.cost;
				uf.unite(e.from, e.to);
			}
		}
		return min_cost;
	}
};


int main(void) {
	while (true) {
		Graph g; 
		cin >> g.n; if (g.n == 0) { break; }
		int m;  cin >> m;
		rep(i, m) {
			int a, b, d; (void)scanf("%d,%d,%d", &a, &b, &d);
			Edge e;
			e.from = a;
			e.to = b;
			e.cost = (d / 100) - 1;

			g.es.push_back(e);

		}
		cout << g.kruskal() << endl;
	}
	return 0;
}