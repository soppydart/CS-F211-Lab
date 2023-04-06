#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(vector<int> vect, int i, int n)
{
    if (i >= n || (i < n && vect.at(i) == -1))
        return NULL;
    Node *ptr = new Node(vect.at(i));
    ptr->left = buildTree(vect, 2 * i + 1, n);
    ptr->right = buildTree(vect, 2 * i + 2, n);
    return ptr;
}

void printPostOrder(Node *node)
{
    if (node == NULL)
        return;
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout << node->data << " ";
}

Node *removeGreater(Node *node, int k)
{
    if (node == NULL)
        return NULL;
    if (node->data <= k)
        node->right = removeGreater(node->right, k);
    else
        return removeGreater(node->left, k);
    return node;
}

Node *removeLesser(Node *node, int k)
{
    if (node == NULL)
        return NULL;
    if (node->data >= k)
        node->left = removeLesser(node->left, k);
    else
        return removeLesser(node->right, k);
    return node;
}

int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> vect(n);
    for (int i = 0; i < n; i++)
        cin >> vect.at(i);
    Node *head = buildTree(vect, 0, n);
    head = removeGreater(head, r);
    head = removeLesser(head, l);
    printPostOrder(head);
    cout << endl;

    return 0;
}