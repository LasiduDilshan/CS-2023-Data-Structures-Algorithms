#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, int m, vector<vector<int>>& edges, int s) {
    vector<vector<int>> adj_list(n + 1);
    for (auto& edge : edges) {
        adj_list[edge[0]].push_back(edge[1]);
        adj_list[edge[1]].push_back(edge[0]);
    }

    vector<int> distances(n + 1, -1); // Initialize distances, -1 means unreachable
    queue<int> q;
    q.push(s);
    distances[s] = 0; // Distance to the starting node is 0

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj_list[node]) {
            if (distances[neighbor] == -1) { // Unvisited node
                distances[neighbor] = distances[node] + 6;
                q.push(neighbor);
            }
        }
    }

    vector<int> result;
    for (int i = 1; i <= n; ++i) {
        if (i != s) {
            result.push_back(distances[i]);
        }
    }
    return result;
}

int main() {
    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(2);
            cin >> edges[i][0] >> edges[i][1];
        }

        int s;
        cin >> s;

        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}