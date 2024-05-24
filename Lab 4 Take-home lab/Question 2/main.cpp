#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

size_t lilysHomework(std::vector<int> arr) {
    std::vector<std::pair<int, size_t>> sortedAsc;
    std::vector<std::pair<int, size_t>> sortedDesc;

    for (size_t i = 0; i < arr.size(); i++) {
        sortedAsc.push_back({ arr[i], i });
        sortedDesc.push_back({ arr[i], i });
    }

    std::sort(sortedAsc.begin(), sortedAsc.end());
    std::sort(sortedDesc.rbegin(), sortedDesc.rend());

    size_t swapCountAsc = 0;
    size_t swapCountDesc = 0;

    for (size_t i = 0; i < sortedAsc.size(); i++) {
        while (i != sortedAsc[i].second) {
            std::swap(sortedAsc[i], sortedAsc[sortedAsc[i].second]);
            swapCountAsc++;
        }
    }

    for (size_t i = 0; i < sortedDesc.size(); i++) {
        while (i != sortedDesc[i].second) {
            std::swap(sortedDesc[i], sortedDesc[sortedDesc[i].second]);
            swapCountDesc++;
        }
    }

    size_t minSwaps = std::min(swapCountAsc, swapCountDesc);

    return minSwaps;
}


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = lilysHomework(arr);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

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
