#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, int& num_cities, int& num_roads) {
    visited[node] = true;
    ++num_cities;
    for (int neighbor : graph[node]) {
        ++num_roads;
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, num_cities, num_roads);
        }
    }
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>>& cities) {
    if (c_lib <= c_road) {
        // It's cheaper to build a library in each city
        return static_cast<long>(n) * c_lib;
    }

    // Build graph from city-road connections
    vector<vector<int>> graph(n + 1);
    for (const auto& road : cities) {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }

    // Find connected components using DFS
    vector<bool> visited(n + 1, false);
    long total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int num_cities = 0, num_roads = 0;
            dfs(i, graph, visited, num_cities, num_roads);
            // Each connected component needs at least 1 library
            total_cost += c_lib;
            // Calculate the cost for roads within this component
            total_cost += min(static_cast<long>(num_cities - 1) * c_road, static_cast<long>(num_roads) * c_lib);
        }
    }
    return total_cost;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, m, c_lib, c_road;
        cin >> n >> m >> c_lib >> c_road;
        vector<vector<int>> cities(m, vector<int>(2));
        for (int i = 0; i < m; ++i) {
            cin >> cities[i][0] >> cities[i][1];
        }
        long result = roadsAndLibraries(n, c_lib, c_road, cities);
        cout << result << endl;
    }
    return 0;
}
