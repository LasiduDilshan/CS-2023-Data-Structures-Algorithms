#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'quickSort' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as a parameter.
 */

vector<int> quickSort(vector<int> arr)
{
    vector<int> leftArr, rightArr, equalArr;

    for (std::vector<int>::size_type i = 0; i < arr.size(); i++)
    {
        if (arr[i] < arr[0])
            leftArr.push_back(arr[i]);
        else if (arr[i] > arr[0])
            rightArr.push_back(arr[i]);
        else
            equalArr.push_back(arr[i]);
    }

    vector<int> finalArr;
    finalArr.reserve(leftArr.size() + equalArr.size() + rightArr.size());

    finalArr.insert(finalArr.end(), leftArr.begin(), leftArr.end());
    finalArr.insert(finalArr.end(), equalArr.begin(), equalArr.end());
    finalArr.insert(finalArr.end(), rightArr.begin(), rightArr.end());

    return finalArr;
}

int main()
{
    ofstream fout(getenv("OUTPUT"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = quickSort(arr);

    for (std::vector<int>::size_type i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << " ";
        }
    }

    cout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
