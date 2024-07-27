#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>>& cities) {
    if (c_lib <= c_road) {
        // It's cheaper to build a library in each city
        return static_cast<long>(n) * c_lib;
    }

    vector<bool> visited(n + 1, false);
    vector<vector<int>> adj_list(n + 1);

    // Constructing adjacency list
    for (auto& road : cities) {
        adj_list[road[0]].push_back(road[1]);
        adj_list[road[1]].push_back(road[0]);
    }

    long total_cost = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            long num_cities = 0;
            long num_roads = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                ++num_cities;
                for (int neighbor : adj_list[curr]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                        ++num_roads;
                    }
                }
            }
            total_cost += c_lib + c_road * (num_cities - 1);
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
