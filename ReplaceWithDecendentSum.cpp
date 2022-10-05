// Given a binary tree , replace every node by sum of all its descendents, leave leaf nodes intact.


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

//Todo: replace with sum
int replaceWithSum(node* root){
    //base case
    if(root == NULL){
        return 0;
    }
    if(root->left ==NULL and root->right == NULL){
        return root->data;
    }

    //rec case
    int LS = replaceWithSum(root->left);
    int RS = replaceWithSum(root->right);

    int temp = root->data;
    root->data = LS + RS;
    return root->data + temp;
}

int main(){
    node* root = levelOrderBuild();
    replaceWithSum(root);
    levelOrderPrint(root);
} 

//Input: 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1