#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* left;
  struct node* right;
  int nheight;
};
struct node* root=NULL;

//Creating a node
struct node* create(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->nheight = 1; //Height of Node
    return temp;
}

int theight(struct node *node){
    if(node == NULL)
        return 0; 
    return node->nheight;
}

int balfac(struct node *node){
    if(node == NULL)
        return 0; 
    return theight(node->left)-theight(node->right);
}

int max(int x, int y){ 
    if(x>y)
        return x;
    else
        return y;
}

struct node *rrotate(struct node *node){
    struct node *temp1 = node->left;
    struct node *temp2 = node->right;
  
    // Perform rotation
    temp1->right = node;
    node->left = temp2;
  
    // Update heights
    node->nheight = max(theight(node->left), theight(node->right))+1;
    temp1->nheight = max(theight(temp1->left), theight(temp1->right))+1; 
  
    return temp1; 
} 
  
// A utility function to left rotate subtree rooted with x 
struct node *lrotate(struct node *node){
    struct node *temp1 = node->right;
    struct node *temp2 = temp1->left;
  
    // Perform rotation 
    temp1->left = node;
    node->right = temp2;
  
    //  Update heights 
    node->nheight = max(theight(node->left), theight(node->right))+1;
    temp1->nheight = max(theight(temp1->left), theight(temp1->right))+1; 
  
    return temp1;
}

struct node* insert(struct node* node, int data){
    if(node == NULL)
        return create(data);

    if(data < node->data)
        node->left = insert(node->left, data);
    else if(data > node->data)
        node->right = insert(node->right, data);

    node->nheight = 1 + max(theight(node->left), theight(node->right));

    int bal = balfac(node);

    // LL Rotation
    if(bal > 1 && data < node->left->data)
        return rrotate(node);
  
    // RR Rotation 
    if(bal < -1 && data > node->right->data)
        return lrotate(node);
  
    // LR Rotation
    if(bal > 1 && data > node->left->data){ 
        node->left =  lrotate(node->left);
        return rrotate(node);
    } 
  
    // RL Rotation
    if(bal < -1 && data < node->right->data){
        node->right = rrotate(node->right);
        return lrotate(node);
    }
    return node;
}

void preorder(struct node* node){
    if(node!=NULL){
        printf("%d ",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

int main(){
    int data, n;
    printf("Number of Nodes: ");
    scanf("%d",&n);
    printf("Enter Values\n");
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        root = insert(root,data);
    }
    
    printf("Preorder Traversal\n");
    preorder(root);
    return 0;
}
