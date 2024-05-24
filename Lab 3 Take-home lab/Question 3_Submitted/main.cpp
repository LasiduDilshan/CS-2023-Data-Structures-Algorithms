#include <iostream>
#include <cmath>

using namespace std;

int powerSum(int X, int N, int num) {
    int val = static_cast<int>(X - pow(num, N));
    if (val < 0) {
        return 0;
    } else if (val == 0) {
        return 1;
    } else {
        return powerSum(val, N, num + 1) + powerSum(X, N, num + 1);
    }
}

int main() {
    int X, N;
    cin >> X >> N;

    int result = powerSum(X, N, 1);

    cout << result << endl;

    return 0;
}
