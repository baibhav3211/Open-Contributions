#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define int long long
using namespace std;
struct node
{
	node* lchild;
	int data;
	node* rchild;
};
node* root = new node;
int count (node *temp)
{
	if (temp)
		return count (temp->lchild) + count (temp->rchild) + 1;
	return 0;
}
int height (node* temp)
{
	int x = 0 , y = 0;
	if (temp==0)
	{
		return 0;
	}
	x = height (temp->lchild);
	y = height (temp->rchild);
	if (x > y) return x + 1;
	else return y + 1;
}
void createTree (int data , queue<node*>& q)
{
	node *p, *t;
	int x;
	root->data = data;
	root->lchild = NULL;
	root->rchild = NULL;
	q.push(root);
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		cout << "Enter the left child of "<<p->data<<" ";
		cin >> x;
		if (x != -1)
		{
			t = new node();
			t->data = x;
			t->rchild = t->lchild = NULL;
			p->lchild = t;
			q.push(t);
		}
		cout << "Enter the right child of " << p->data << " ";
		cin >> x;
		if (x != -1)
		{
			t = new node();
			t->data = x;
			t->rchild = t->lchild = NULL;
			p->rchild = t;
			q.push(t);
		}
	}
}

void preorder(node* p)
{
	// node *p=root;
	if (p)
	{
		cout << p->data << " ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
void inorder(node* p)
{
	// node *p=root;
	if (p)
	{
		inorder(p->lchild);
		cout << p->data << " ";
		inorder(p->rchild);
		
	}
}
void postorder(node* p)
{
	// node *p=root;
	if (p)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		cout << p->data << " ";
	}
}
void levelorder(node* p)
{
	node *t;
	queue<node*> q;
	q.push(root);
	cout << root->data << " ";
	while (!q.empty())
	{
		t = q.front();
		q.pop();
		if (t->lchild)
		{
			cout << t->lchild->data << " ";
			q.push(t->lchild);
		}
		if (t->rchild)
		{
			cout << t->rchild->data << " ";
			q.push(t->rchild);
		}
	}
}
int32_t main()
{
	queue<node*> q;
	int rdata;
	cout << "Enter root data ";
	cin >> rdata;
	createTree(rdata, q);
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	levelorder(root);
	cout << endl;
	cout << "Count :- " << count (root)<<endl;
	cout << "Height :- " << height (root)-1<<endl;
}