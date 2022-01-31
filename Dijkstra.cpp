class Dijkstra {
public:
	vector<int> shortestDistance(vector<vector<pair<int, int>>>&g, int src) {
		// assuming 0 based indexing and no negative edges present
		// works well even for directed cyclic graph
		// g[i] of the form (node, weight of edge from i -> node)
		int n = g.size();
		const int INF = INT_MAX;
		vector<int>dist(n, INF);
		dist[src] = 0;
		// element of pq of the form (distance,node)
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
		q.push({dist[src], src});
		while (!q.empty()) {
			int cur_node = q.top().second;
			q.pop();
			for (auto &x : g[cur_node]) {
				int next_node = x.first;
				int weight = x.second;
				if (dist[next_node] > dist[cur_node] + weight) {
					dist[next_node] = dist[cur_node] + weight;
					q.push({dist[next_node], next_node});
				}
			}
		}
		return dist;
	}
};
