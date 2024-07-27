string twoStrings(string s1, string s2) {
    for (size_t i = 0; i < s1.length(); ++i) {
        if (s2.find(s1[i]) != string::npos) {
            return "YES";
        }
    }
    return "NO";
}