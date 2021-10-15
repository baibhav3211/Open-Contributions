#include <iostream>
#include <queue>
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

void preorder(Node *r)
{

    if (r == NULL)
        return;

    cout << r->data << ", ";
    preorder(r->left);
    preorder(r->right);
}

void inorder(Node *r)
{

    if (r == NULL)
        return;

    inorder(r->left);
    cout << r->data << ", ";
    inorder(r->right);
}

void postorder(Node *r)
{

    if (r == NULL)
        return;

    postorder(r->left);
    postorder(r->right);
    cout << r->data << ", ";
}

void levelOrder(Node *r)
{
    if (r == NULL)
        return;

    queue<Node *> q;
    q.push(r);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();

        q.pop();

        if (node != NULL)
        {
            cout << node->data << ", ";

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

int sumAtK(Node *r, int k)
{
    if (r == NULL)
        return -1;

    queue<Node *> q;
    q.push(r);
    q.push(NULL);

    int level = 0, sum = 0;

    while (!q.empty())
    {
        Node *node = q.front();

        q.pop();

        if (node != NULL)
        {
            if (level == k)
            {
                sum += node->data;
            }

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }

    return sum;
}

int nodesInTree(Node *r)
{
    if (r == NULL)
        return 0;

    return nodesInTree(r->left) + nodesInTree(r->right) + 1;
}

int nodesSum(Node *r)
{
    if (r == NULL)
        return 0;

    return nodesSum(r->left) + nodesSum(r->right) + r->data;
}

int calcHeight(Node *r)
{
    if (r == NULL)
        return 0;

    int lHeight = calcHeight(r->left);
    int rHeight = calcHeight(r->right);

    return max(lHeight, rHeight) + 1;
}

int calcDiameter(Node *r) // O(n^2)
{
    if (r == NULL)
        return 0;

    int lHeight = calcHeight(r->left);
    int rHeight = calcHeight(r->right);
    int currentDia = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(r->left);
    int rDiameter = calcDiameter(r->right);

    return max(currentDia, max(lDiameter, rDiameter));
}

int calcDiameter(Node *r, int *height) // O(n)
{
    if (r == NULL)
    {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int lDiameter = calcDiameter(r->left, &lh);
    int rDiameter = calcDiameter(r->right, &rh);

    int currentDia = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currentDia, max(lDiameter, rDiameter));
}

void sumReplace(Node *r)
{
    if (r == NULL)
        return;

    sumReplace(r->left);
    sumReplace(r->right);

    if (r->left != NULL)
        r->data += r->left->data;
    if (r->right != NULL)
        r->data += r->right->data;
}

bool isBalanced(Node *r) // O(n^2)
{
    if (r == NULL)
        return true;
    if (!isBalanced(r->left))
        return false;
    if (!isBalanced(r->right))
        return false;

    int lh = calcHeight(r->left);
    int rh = calcHeight(r->right);

    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
}

bool isBalanced(Node *r, int *h) // O(n)
{
    if (r == NULL)
        return true;

    int lh = 0, rh = 0;
    if (!isBalanced(r->left, &lh))
        return false;
    if (!isBalanced(r->right, &rh))
        return false;

    *h = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1)
        return true;
    else
        return false;
}

void rightView(Node *r)
{
    if (r == NULL)
        return;

    queue<Node *> q;
    q.push(r);

    while (!q.empty())
    {

        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front();
            q.pop();

            if (i == n - 1)
            {
                cout << node->data << ", ";
            }

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
}

void leftView(Node *r)
{
    if (r == NULL)
        return;

    queue<Node *> q;
    q.push(r);

    while (!q.empty())
    {

        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front();
            q.pop();

            if (i == 0)
            {
                cout << node->data << ", ";
            }

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
}

// ======================
// ======== MAIN ========
// ======================

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    /*
        1
       / \
      2   3
    */

    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /*
          1
       /    \
      2      3
     / \    / \
    4   5  6   7
    */

    preorder(root); // 1,2,4,5,3,6,7
    cout << endl;
    inorder(root); // 4,2,5,1,6,3,7
    cout << endl;
    postorder(root); // 4,5,2,6,7,3,1
    cout << endl;
    levelOrder(root); // 1,2,3,4,5,6,7
    cout << endl;
    cout << sumAtK(root, 1); // 5
    cout << endl;
    cout << sumAtK(root, 2); // 22
    cout << endl;
    cout << nodesInTree(root); // 7
    cout << endl;
    cout << nodesSum(root); // 28
    cout << endl;
    cout << calcHeight(root); // 3
    cout << endl;
    cout << calcDiameter(root); // 5
    cout << endl;
    int h = 0;
    cout << calcDiameter(root, &h); // 5
    cout << endl;
    rightView(root);
    cout << endl;
    leftView(root);
    cout << endl;
    sumReplace(root);
    preorder(root); // 28,11,4,5,16,6,7
    cout << endl;
    cout << isBalanced(root);

    return 0;
}