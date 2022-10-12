// Given a binary tree, we need to print it vertically.
// Level Order print of tree is given as input shown:
//        1
//       /\
//      2  3
//     /\   /\
//     4 5 6 7
//         \  \
//         8   9

// Output:
// 4
// 2 
// 1 5 6
// 3 8
// 7 
// 9

// While traversing we store the distance and node in a map map<distance, vector<int>>

// 0 -> (1)
// -1 -> (2)
// -2 -> (4)
// ........
 

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

void verticalPrint(node* root){

    map<int, vector<int>> m;
    // initially distance = 0
    int d=0;
    traverseTree(root,d, m);
    //keys are sorted (-2, -1, 0, 1.....)
    for(auto p:m){
        int key = p.first;
        vector<int> line = p.second;
        for(auto data: line){
            cout<<data<<" ";
        }
        cout<<endl;
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

    verticalPrint(root);
    return 0;
}