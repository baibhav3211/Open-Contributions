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

Node *buildTree(int post[], int in[], int start, int end)
{
    static int i = 4;

    if (start > end)
    {
        return NULL;
    }

    int curr = post[i--];
    Node *node = new Node(curr);

    if (start == end)
    {
        return node;
    }

    int pos = search(in, start, end, curr);
    node->right = buildTree(post, in, pos + 1, end);
    node->left = buildTree(post, in, start, pos - 1);

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

int main()
{
    int post[] = {4, 2, 5, 3, 1};
    int in[] = {4, 2, 1, 5, 3};

    Node *root = buildTree(post, in, 0, 4);

    /*
            1
           / \
          2   3
         /   /
        4   5
    */

    inorder(root);
    return 0;
}