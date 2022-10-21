// Given a binary tree, and a target node T. Find all nodes at distance K from given node, where K is also an integer input.

#include<bits/stdc++.h>
using namespace std;

class node{

    public:
        int data;
        node* left;
        node* right;

        node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

// Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 6 -1 -1

node* buildTree(){
    // preorder build method
    int val;
    cin >> val;
    if(val == -1){
        return NULL;
    }
    node* root = new node(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// Implement a level order traversal 
// Expected Output
/*
1
2 3
4 5 6
7 
*/

void levelOrderPrint(node* root){

    queue<node* > q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();
            // Insert a new null for the next level
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    // return;
}

node* levelOrderBuild(){

    int d;
    cin>>d;

    node* root = new node(d);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* curr = q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1){
            curr->left = new node(c1);
            q.push(curr->left);
        }
        if(c2!=-1){
            curr->right = new node(c2);
            q.push(curr->right);
        }
    }
    return root;
}

void printAtLevelK(node* root, int k){
    if(root==NULL){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printAtLevelK(root->left, k-1);
    printAtLevelK(root->right, k-1);
    return;
}

int nodesAtDistanceK(node* root, node* target, int k){
    //base case
    if(root==NULL){
        return -1; //did not find
    }

    //reached the target
    if(root==target){
        printAtLevelK(target, k);
    }


    //other case
    int dl = nodesAtDistanceK(root->left, target, k);
    if(dl!=-1){
        //print the current node
        if(dl+1==k){
            cout<<root->data;
        }
        //or print some nodes in the right subtree
        else{
            printAtLevelK(root->right, k-2-dl);
        }
        return 1+dl;
    }

    int dr = nodesAtDistanceK(root->right, target, k);
    if(dr!=-1){
        //print the current node
        if(dr+1==k){
            cout<<root->data;
        }
        //or print some nodes in the right subtree
        else{
            printAtLevelK(root->left, k-2-dl);
        }
        return 1+dr;
    }
    return -1;
}

int main(){
    node* root = levelOrderBuild();
    levelOrderPrint(root);
    int k=2;
    node* target = root->left->right;
    nodesAtDistanceK(root,target,k);
    return 0;
}