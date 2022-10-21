#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node* left;
  struct node* right;
};
struct node* root=NULL;

//Creating a Node
struct node* create(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//Inserting Node in the Tree
struct node* insert(struct node* node, int data){
    if(node==NULL)
        return create(data);
    else if(data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

//Searching 
int search(struct node* node, int data){
    if(node!= NULL && node->data == data){
        return 1;
    }
    else
        return 0;
    if(data < node->data)
        search(node->left, data);
    else if(data > node->data)
        search(node->right, data);
}

//function to find the minimum value
struct node* min(struct node *root){
    if(root == NULL)
        return NULL;
    else if(root->left != NULL) // node with minimum value will have no left child
        return min(root->left); // left most element will be minimum
    return root;
}

//Deleting a Node
struct node* delete(struct node *root, int data){
    if(root==NULL)
        return NULL;
    if(data > root->data)
        root->right = delete(root->right, data);
    else if(data < root->data)
        root->left = delete(root->left, data);
    else{
        //Node is a leaf node
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left==NULL || root->right==NULL){
            struct node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }

        //Two Children
        else{
            struct node *temp = min(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

void preorder(struct node* node){
    if(node!=NULL){
        printf("%d ",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(struct node* node){
    if(node!=NULL){
        inorder(node->left);
        printf("%d ",node->data);
        inorder(node->right);
    }
}

void postorder(struct node* node){
    if(node!=NULL){
        postorder(node->left);
        postorder(node->right);
        printf("%d ",node->data);
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
    printf("\nInorder Traversal\n");
    inorder(root);
    printf("\nPostorder Traversal\n");
    postorder(root);
    
    printf("\nValue to Search: ");
    scanf("%d",&data);
    int x = search(root,data);
    if(x)
        printf("Found\n");
    else
        printf("Not Found\n");

    printf("Enter value to delete: ");
    scanf("%d",&data);
    delete(root, data);
    preorder(root);
    return 0;
}
