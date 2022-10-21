#include <iostream>
using namespace std;

struct Node
{
    struct Node *right;
    struct Node *left;
    int x;

    Node(int x)
    {
        this->x = x;
        right = NULL;
        left = NULL;
    }
};

Node *buildBST(Node *r, int val)
{
    if (r == NULL)
    {
        return new Node(val);
    }

    if (r->x > val)
    {
        r->left = buildBST(r->left, val);
    }
    else
    {
        r->right = buildBST(r->right, val);
    }

    return r;
}

void inOrder(Node *r)
{
    if (r == NULL)
        return;

    inOrder(r->left);
    cout << r->x << ", ";
    inOrder(r->right);
}

bool BSTsearch(Node *r, int val)
{
    if (r == NULL)
        return false;
    if (r->x == val)
        return true;

    if (r->x > val)
    {
        return BSTsearch(r->left, val);
    }

    return BSTsearch(r->right, val);
}

Node *inorderSucc(Node *r)
{
    Node *curr = r;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *BSTdelete(Node *r, int val)
{
    if (val < r->x)
    {
        r->left = BSTdelete(r->left, val);
    }
    else if (val > r->x)
    {
        r->right = BSTdelete(r->right, val);
    }
    else
    {
        if (r->left == NULL)
        {
            Node *temp = r->right;
            free(r);
            return temp;
        }
        else if (r->right == NULL)
        {
            Node *temp = r->left;
            free(r);
            return temp;
        }

        Node *temp = inorderSucc(r->right);
        r->x = temp->x;
        r->right = BSTdelete(r->right, temp->x);
    }
    return r;
}

int main()
{

    int a[] = {5, 1, 3, 4, 2, 7};
    Node *root = NULL;
    for (int i = 0; i < 6; ++i)
    {
        root = buildBST(root, a[i]);
    }

    /*
        5
       / \
      1   7
       \
        3
       / \
      2   4
    */

    inOrder(root);
    cout << endl;
    cout << BSTsearch(root, 7);

    return 0;
}
