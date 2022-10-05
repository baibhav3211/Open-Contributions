// Build a binary tree from level order input , -1 in input 
// represents NULL

// 1 2 3 4 5 -1 6 -1 -1 7 -1 -1 -1 -1
// Key things:
// 1. Create the root node
// 2. Do BFS type approach and read two numbers every time then create and attach the nodes.

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

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1+max(h1, h2);
}

// Time complexity O(n^2)

int diameter(node* root){
    //base case
    if(root==NULL){
        return 0;
    }
    //rec case
    int D1 = height(root->left)+height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);

    return max(D1, max(D2, D3));
}

//Optimised code for diameter calculation
// We try to find height and dimater as pair at each node and using pair and try to evaluate the dimater and height
// O(n)
//Example of postorder traversal 
class HDPair{
    public:
        int height;
        int diameter;
};

HDPair optDiameter(node* root){
    HDPair p;
    if(root==NULL){
        p.height = p.diameter = 0;
        return p;
    }
    //otherwise
    HDPair Left = optDiameter(root->left);
    HDPair Right = optDiameter(root->right);

    p.height = max(Left.height, Right.height) + 1;
    int D1 = Left.height + Right.height;
    int D2 = Left.diameter;
    int D3 = Right.diameter;

    p.diameter = max(D1, max(D2, D3));
    return p;
}

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
    return;
}


int main(){
    // node* root = levelOrderBuild();
    node* root = buildTree();
    levelOrderPrint(root);
    cout<<"Diameter is: "<<diameter(root)<<endl;
    cout<<"Optimsied Code's Diameter is:"<<optDiameter(root).diameter<<endl;
}