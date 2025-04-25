class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Adjacency list representation of the graph
        vector<vector<pair<int, int>>> adj(n);

        // Initially add edges from i to j (for all i < j) with weight j - i
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                adj[i].emplace_back(j, j - i);
            }
        }

        vector<int> ans;

        // Process each query
        for (auto& query : queries) {
            int from = query[0];
            int to = query[1];

            // Add a new edge with weight 1
            adj[from].emplace_back(to, 1);

            // Run BFS (0-1 BFS is not needed here since edge weights are small and positive)
            vector<int> dist(n, INT_MAX);
            queue<int> q;

            dist[0] = 0;
            q.push(0);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (auto [v, weight] : adj[u]) {
                    if (dist[v] > dist[u] + weight) {
                        dist[v] = dist[u] + weight;
                        q.push(v);
                    }
                }
            }
            ans.push_back(dist[n - 1]);
        }

        return ans;
    }
};
