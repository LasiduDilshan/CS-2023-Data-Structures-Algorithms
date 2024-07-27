#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to maintain the min-heap property after adding an element
void heapifyUp(vector<int>& heap, int idx) {
    while (idx > 0 && heap[(idx - 1) / 2] > heap[idx]) {
        swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

// Function to maintain the min-heap property after deleting an element
void heapifyDown(vector<int>& heap, int idx, int n) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != idx) {
        swap(heap[idx], heap[smallest]);
        heapifyDown(heap, smallest, n);
    }
}

int main() {
    int q;
    cin >> q;

    vector<int> heap;
    while (q--) {
        int type, num;
        cin >> type;
        if (type == 1) {
            cin >> num;
            heap.push_back(num);
            heapifyUp(heap, heap.size() - 1);
        } else if (type == 2) {
            cin >> num;
            int idx = find(heap.begin(), heap.end(), num) - heap.begin();
            swap(heap[idx], heap.back());
            heap.pop_back();
            heapifyDown(heap, idx, heap.size());
        } else if (type == 3) {
            cout << heap[0] << endl;
        }
    }

    return 0;
}
