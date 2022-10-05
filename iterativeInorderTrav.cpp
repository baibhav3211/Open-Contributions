#include<bits/stdc++.h>
using namespace std;

struct node{
    public:
        int data;
        struct node* left, *right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(node* root){
    struct node* curr = root;
    stack<node* > s;
    while(curr!=NULL || !s.empty()){
        while(curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr = curr->right;
    }

}


int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    inorder(root);
    return 0;
}