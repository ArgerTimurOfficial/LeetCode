class Solution {
 public:
  vector<vector<int>> criticalConnections(int n,
vector<vector<int>>& connections) {
    vector<vector<int>> ans;
    vector<vector<int>> graph(n);
    for (const auto& conn : connections) {
      const int u = conn[0];
      const int v = conn[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    getRank(graph, 0, 0, vector<int>(n, NO_RANK), ans);
    return ans;
  }
 private:
  constexpr static int NO_RANK = -2;
  int getRank(const vector<vector<int>>& graph, int u, int currRank,
              vector<int>&& rank, vector<vector<int>>& ans) {
    if (rank[u] != NO_RANK)
      return rank[u];
    rank[u] = currRank;
    int minRank = currRank;
    for (const int v : graph[u]) {
      if (rank[u] == rank.size() || rank[v] == currRank - 1)continue;
      const int nextRank = getRank(graph, v, currRank + 1, move(rank), ans);
      if (nextRank == currRank + 1)
        ans.push_back({u, v});
      minRank = min(minRank, nextRank);
    }
    rank[u] = rank.size();
    return minRank;
  }
};