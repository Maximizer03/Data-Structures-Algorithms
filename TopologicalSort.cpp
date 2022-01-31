class TopologicalSort {
public:
	void order(vector<vector<int>>&g) {
		// assuming directed graph
		int n = g.size();
		vector<int>ord;
		vector<int>indegree(n, 0);
		for (int i = 0; i < n; i++) {
			for (auto &u : g[i]) {
				indegree[u]++;
			}
		}
		queue<int>q;
		for (int i = 0; i < n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		if (q.empty()) {
			cout << "Cycle is present" << endl;
			return;
		}
		int cnt = 0;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			ord.push_back(v);
			cnt++;
			for (auto &u : g[v]) {
				indegree[u]--;
				if (indegree[u] == 0) {
					q.push(u);
				}
			}
		}
		if (cnt < n) {
			cout << "Cycle is present" << endl;
			return;
		}
		for (auto &v : ord) {
			cout << v << " ";
		}
		cout << endl;
	}
};
