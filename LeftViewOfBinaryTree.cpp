//Same type of approach as in finding the vertical order of the tree


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


// node* buildTree(){
//     // preorder build method
//     int val;
//     cin >> val;
//     if(val == -1){
//         return NULL;
//     }
//     node* root = new node(val);
//     root->left = buildTree();
//     root->right = buildTree();
//     return root;
// }

//helper function
void traverseTree(node* root, int d, map<int, vector<int>> &m){
    if(root==NULL){
        return;
    }
    m[d].push_back(root->data);
    traverseTree(root->left, d-1, m);
    traverseTree(root->right, d+1, m);
}

// void verticalPrint(node* root){

//     map<int, vector<int>> m;
//     // initially distance = 0
//     int d=0;
//     traverseTree(root,d, m);
//     //keys are sorted (-2, -1, 0, 1.....)
//     for(auto p:m){
//         int key = p.first;
//         vector<int> line = p.second;
//         for(auto data: line){
//             cout<<data<<" ";
//         }
//         cout<<endl;
//     }
//     return;
// }

void leftViewOfBinaryTree(node* root){
    if(root==NULL){
        return;
    }
    queue<node* > q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=1;i<=n;i++){
            node* temp = q.front();
            q.pop();
            if(i==1){
                cout<<temp->data<<" ";
            }
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
    return;
}

int main(){
    // node* root = buildTree();
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);

    leftViewOfBinaryTree(root);
    return 0;
}