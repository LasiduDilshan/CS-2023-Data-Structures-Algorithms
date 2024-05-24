#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */

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
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);
        int m = stoi(first_multiple_input[1]);
        int c_lib = stoi(first_multiple_input[2]);
        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);
            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);
            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));
            for (int j = 0; j < 2; j++) {
                int cities_row_item = stoi(cities_row_temp[j]);
                cities[i][j] = cities_row_item;
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);
        cout << result << "\n";
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start));
    return tokens;
}
