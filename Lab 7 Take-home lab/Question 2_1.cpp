#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cookies(int k, vector<int> A) {
    // Create a min-heap to store sweetness levels of cookies
    priority_queue<int, vector<int>, greater<int>> minHeap(A.begin(), A.end());

    int operations = 0;

    // While there are at least 2 cookies and the minimum sweetness is less than k
    while (minHeap.size() >= 2 && minHeap.top() < k) {
        // Combine the two least sweet cookies
        int leastSweet = minHeap.top();
        minHeap.pop();
        int secondLeastSweet = minHeap.top();
        minHeap.pop();
        int newSweetness = leastSweet + 2 * secondLeastSweet;
        
        // Push the combined sweetness back to the heap
        minHeap.push(newSweetness);
        
        // Increment the number of operations
        operations++;
    }

    // Check if the minimum sweetness is still less than k
    if (!minHeap.empty() && minHeap.top() < k) {
        return -1; // It's not possible to achieve the required sweetness
    }

    return operations;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int result = cookies(k, A);
    cout << result << endl;

    return 0;
}
