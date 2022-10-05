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

int main(){
    node* root = buildTree();
    levelOrderPrint(root);
}