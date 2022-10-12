// Given a binary tree , check if it is height balanced .
// A non-empty binary tree T is balanced if:
// 1) Left subtree of T is balanced
// 2) Right subtree of T is balanced
// 3) The difference between heights of left subtree and right 
// subtree is not more than 1.


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

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    return 1+max(lh, rh);
}
// O(n^2)
bool isBalanced(node* root){
    if(root==NULL){
        return true;
    }
    if(isBalanced(root->left) == false){
        return false;
    }
    if(isBalanced(root->right) == false){
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh-rh)<=1){
        return true;
    }else{
        return false;
    }
}

//Optimised code  O(n)  Postorder Traversal
pair<int, bool> isHeightBalanced(node* root){
    pair<int, bool> p, Left, Right;
    if(root==NULL){
        p.first = 0;  //height
        p.second = true;  //balanced
        return p;
    }

    //recursive case
    Left = isHeightBalanced(root->left);
    Right = isHeightBalanced(root->right);

    int height = max(Left.first, Right.first) + 1;

    if(abs(Left.first - Right.first)<=1 and Left.second and Right.second){
        return make_pair(height, true);
    }
    return make_pair(height, false);

}

int main(){
    node* root = levelOrderBuild();
    levelOrderPrint(root);
    if(isBalanced(root)){
        cout<<"balanced tree"<<endl;
    }else{
        cout<<"Not balanced"<<endl;
    }

    pair<int, bool> p = isHeightBalanced(root);
    if(p.second){
        cout<<"balanced tree using optimised"<<endl;
    }else{
        cout<<"Not balanced"<<endl;
    }
}