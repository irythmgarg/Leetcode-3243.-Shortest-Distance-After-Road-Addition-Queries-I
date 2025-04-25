class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        // Initialize an adjacency matrix to represent distances between nodes
        // Initially, set all distances to INT_MAX (infinite)
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
        
        // Set initial distances in the graph
        for (int i = 0; i < n; ++i) {
            adj[i][i] = 0; // Distance from a node to itself is 0
            for (int j = i + 1; j < n; ++j) {
                adj[i][j] = j - i; // Direct edge with weight equal to the difference in indices
            }
        }

        vector<int> ans; // To store the result after each query
        
        // Process each query
        for (auto query : queries) {
            int from = query[0];
            int to = query[1];

            // Update the direct path from `from` to `to` with weight 1
            adj[from][to] = 1;

            // Propagate the new shortest paths using a form of dynamic update (like a partial Floyd-Warshall step)
            for (int i = 0; i < n; ++i) {
                if (adj[i][from] == INT_MAX) continue; // Skip if there's no path to 'from'

                for (int j = 0; j < n; ++j) {
                    if (adj[to][j] == INT_MAX) continue; // Skip if there's no path from 'to'
                    
                    // Update the shortest path from i to j via the new edge from 'from' to 'to'
                    adj[i][j] = min(adj[i][j], adj[i][from] + 1 + adj[to][j]);
                }
            }

            // Append the shortest distance from node 0 to node n-1 after this query
            ans.push_back(adj[0][n-1]);
        }

        return ans;
    }
};
