#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Define custom swap function
void mySwap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapifyUp(vector<int>& heap, int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        mySwap(heap[index], heap[(index - 1) / 2]); // Use custom swap function
        index = (index - 1) / 2;
    }
}

void heapifyDown(vector<int>& heap, int index, int n) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        mySwap(heap[index], heap[smallest]); // Use custom swap function
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
            int index = find(heap.begin(), heap.end(), num) - heap.begin();
            mySwap(heap[index], heap.back()); // Use custom swap function
            heap.pop_back();
            heapifyDown(heap, index, heap.size());
        } else if (type == 3) {
            cout << heap[0] << endl;
        }
    }

    return 0;
}
