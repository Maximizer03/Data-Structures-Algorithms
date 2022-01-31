class TopologicalSort {
private:
	vector<int>parent, rank;
public:
	void init(int n) {
		parent.resize(n + 1);
		rank.resize(n + 1);
		for (int v = 0; v <= n; v++) {
			parent[v] = v;
			rank[v] = v;
		}
	}
	int find_set(int v) {
		if (v == parent[v]) {
			return parent[v];
		}
		return parent[v] = find_set(parent[v]);
	}
	void union_sets(int a, int b) {
		a = find_set(a);
		b = find_set(b);
		if (a != b) {
			if (rank[a] < rank[b]) {
				swap(a, b);
			}
			parent[b] = a;
			if (rank[a] == rank[b]) {
				rank[a]++;
			}
		}
	}
};
