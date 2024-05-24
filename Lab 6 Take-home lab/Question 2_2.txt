#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int x) {
    if (root == nullptr) {
        return new Node(x);
    }
    if (x < root->val) {
        root->left = insert(root->left, x);
    } else {
        root->right = insert(root->right, x);
    }
    return root;
}

Node* lca(Node* root, int v1, int v2) {
    if (root == nullptr) {
        return nullptr;
    }

    if (v1 < root->val && v2 < root->val) {
        return lca(root->left, v1, v2);
    } else if (v1 > root->val && v2 > root->val) {
        return lca(root->right, v1, v2);
    } else {
        return root;
    }
}

int main() {
    Node* root = nullptr;
    int numNodes;
    //cout << "Enter the number of nodes in the binary search tree: ";
    cin >> numNodes;

    //cout << "Enter the values of the nodes:" << endl;
    for (int i = 0; i < numNodes; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int node1, node2;
    //cout << "Enter the values of the two nodes to find their Lowest Common Ancestor: ";
    cin >> node1 >> node2;

    Node* result = lca(root, node1, node2);

    //cout << "Lowest Common Ancestor: " << endl;
    cout <<  result->val << endl;

    return 0;
}