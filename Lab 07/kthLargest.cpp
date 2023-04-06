#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c = 0;
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

void solve(Node *node, int k)
{
    if (!node)
        return;
    solve(node->right, k);
    c++;
    if (c == k)
        cout << node->data << endl;
    solve(node->left, k);
}

int main()
{
    int n, k;
    cin >> n;
    vector<int> vect(n);
    for (int i = 0; i < n; i++)
        cin >> vect.at(i);
    cin >> k;
    Node *head = buildTree(vect, 0, n);
    solve(head, k);

    return 0;
}