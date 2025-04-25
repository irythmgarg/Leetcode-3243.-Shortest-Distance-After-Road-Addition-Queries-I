# Leetcode-3243.-Shortest-Distance-After-Road-Addition-Queries-I
# 🚀 Dynamic Shortest Path After Queries

This project provides two implementations to solve the **dynamic shortest path problem** in a directed graph with `n` nodes. Given a series of edge-adding queries, it computes the shortest path from node `0` to node `n - 1` **after each query**.

---

## 🧠 Problem Statement

- You have a directed graph with `n` nodes (0-indexed).
- Initially, there is an edge from node `i` to node `j` (where `i < j`) with weight `j - i`.
- Each query adds a directed edge `from → to` with weight `1`.
- After each query, return the shortest distance from node `0` to node `n - 1`.

---

## 💡 Approaches

### 🔁 1. Matrix-Based Dynamic Update (Floyd-Warshall Inspired)

- ✅ Uses a 2D matrix to store and update shortest paths.
- 🔧 On each query, the new edge is added and distance matrix is updated by considering indirect paths using that edge.
- ⚡ Efficient for small graphs (`n <= 1000`).

#### 🔍 Logic

- Use the distance matrix `adj[i][j]` where `adj[i][j] = minimum distance from i to j`.
- On adding edge `u → v`, update all pairs `i → j` as:
adj[i][j] = min(adj[i][j], adj[i][u] + 1 + adj[v][j])


#### 📄 Code

See [`shortestDistance_FloydStyle.cpp`](./shortestDistance_FloydStyle.cpp)

---

### 🔗 2. BFS-Based Approach (Recompute Every Time)

- ✅ Uses an adjacency list for the graph.
- 🔁 After each query, perform **BFS** from node `0` to compute the shortest distance.
- ⚠️ Recomputes from scratch on every query, but works well with sparse updates and moderate `n`.

#### 🔍 Logic

- Add the new edge `u → v` with weight `1` to the adjacency list.
- Run BFS (or optionally Dijkstra) from node `0` to find shortest path to `n - 1`.

#### 📄 Code

See [`shortestDistance_BFS.cpp`](./shortestDistance_BFS.cpp)

---

## 📊 Example

```cpp
n = 4
queries = [[0, 2], [1, 3]]

Initial edges:
0 → 1 (1), 0 → 2 (2), 0 → 3 (3)
1 → 2 (1), 1 → 3 (2)
2 → 3 (1)

Query 1: Add 0 → 2 (1)
Query 2: Add 1 → 3 (1)

Output: [2, 2]


📌 Notes
For larger graphs or many updates, consider a fully dynamic shortest path algorithm or a 0-1 BFS version.

Edge case: If no path exists from 0 to n - 1, output would be INT_MAX.

