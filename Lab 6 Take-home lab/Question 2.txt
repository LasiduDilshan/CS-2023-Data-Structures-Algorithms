#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right;
    Node(int x)
    {
        val = x;
        left = right = NULL;
    }
};
Node *insert(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);
    if (x < root->val)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

Node *lca(Node *root, int v1, int v2)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (v1 < root->val && v2 < root->val)
    {
        return lca(root->left, v1, v2);
    }
    else if (v1 > root->val && v2 > root->val)
    {
        return lca(root->right, v1, v2);
    }
    else
    {
        return root;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    int v1, v2;
    cin >> v1 >> v2;

    Node *result = lca(root, v1, v2);

    cout << result->val;
}