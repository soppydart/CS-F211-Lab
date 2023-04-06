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

Node *solve(vector<int> in, vector<int> pre, int is, int ie, int ps, int pe)
{
    if (is > ie)
        return NULL;
    int rootdata = pre[ps], index = -1;
    for (int i = is; i <= ie; i++)
    {
        if (in[i] == rootdata)
        {
            index = i;
            break;
        }
    }
    int lis = is;
    int lie = index - 1;
    int lps = ps + 1;
    int lpe = lie - lis + lps;
    int ris = index + 1;
    int rie = ie;
    int rps = lpe + 1;
    int rpe = pe;
    Node *root = new Node(rootdata);
    root->left = solve(in, pre, lis, lie, lps, lpe);
    root->right = solve(in, pre, ris, rie, rps, rpe);
    return root;
}

int maxDepth(Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void makeAns(vector<int> &ans, Node *node, int i)
{
    if (!node)
        return;
    ans.at(i) = node->data;
    makeAns(ans, node->left, 2 * i + 1);
    makeAns(ans, node->right, 2 * i + 2);
}

int main()
{
    int n;
    cin >> n;
    vector<int> pre(n), in(n);
    for (int i = 0; i < n; i++)
        cin >> pre.at(i);
    for (int i = 0; i < n; i++)
        cin >> in.at(i);
    Node *head = solve(in, pre, 0, n - 1, 0, n - 1);
    int d = maxDepth(head);
    vector<int> ans(pow(2, d), -1);
    makeAns(ans, head, 0);
    while (ans.back() == -1)
        ans.pop_back();
    for (int i = 0; i < ans.size(); i++)
        cout << ans.at(i) << " ";
    cout << endl;

    return 0;
}