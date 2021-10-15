#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        this->data = val;
        left = right = NULL;
    }
};

int search(int in[], int start, int end, int curr)
{
    for (int i = start; i <= end; ++i)
    {
        if (in[i] == curr)
            return i;
    }
    return -1;
}

Node *buildTree(int pre[], int in[], int start, int end)
{
    static int i = 0;

    if (start > end)
    {
        return NULL;
    }

    int curr = pre[i++];
    Node *node = new Node(curr);

    if (start == end)
    {
        return node;
    }

    int pos = search(in, start, end, curr);
    node->left = buildTree(pre, in, start, pos - 1);
    node->right = buildTree(pre, in, pos + 1, end);

    return node;
}

void inorder(Node *r)
{

    if (r == NULL)
        return;

    inorder(r->left);
    cout << r->data << ", ";
    inorder(r->right);
}

Node *LCA(Node *r, int n1, int n2)
{
    if (r == NULL)
        return NULL;

    if (r->data == n1 || r->data == n2)
        return r;

    Node *left = LCA(r->left, n1, n2);
    Node *right = LCA(r->right, n1, n2);

    if (left != NULL && right != NULL)
    {
        return r;
    }

    if (left == NULL && right == NULL)
    {
        return NULL;
    }

    if (left != NULL)
    {
        return LCA(r->left, n1, n2);
    }

    return LCA(r->right, n1, n2);
}

int findDist(Node *r, int k, int dist)
{
    if (r == NULL)
        return -1;
    if (r->data == k)
        return dist;

    int left = findDist(r->left, k, dist + 1);
    if (left != -1)
        return left;

    return findDist(r->right, k, dist + 1);
}

int distanceBtwNodes(Node *r, int n1, int n2)
{
    Node *lca = LCA(r, n1, n2);

    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);

    return d1 + d2;
}

int main()
{
    int pre[] = {1, 2, 4, 3, 5, 6};
    int in[] = {4, 2, 1, 5, 3, 6};

    Node *root = buildTree(pre, in, 0, 5);

    /*
            1
           / \
          2   3
         /   / \
        4   5   6
    */

    inorder(root);
    cout << endl;
    cout << distanceBtwNodes(root, 2, 6);

    return 0;
}