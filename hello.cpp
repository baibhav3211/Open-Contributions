#include <stdio.h> #include <stdlib.h> #include<stdbool.h> #include<limits.h>
/* Structure definition for employee node */
struct node { int id; 	struct node* left; 	struct node* right; 	struct node* parent; };
/* Structure definition for employee node Queue */
struct queue { struct node* arr[100]; 	int front , rear; };
/* Function to check if the Queue is empty or not */
bool isEmptyQueue (struct queue* q) { return (q->front == q->rear) ? true : false; }
/* Function to insert an element in the Queue */
void enqueue (struct queue* q , struct node* child) { q->arr[++(q->rear)] = child; 	return; }
/* Function to delete an element from the Queue*/
struct node* dequeue (struct queue* q) { return q->arr[++(q->front)]; }
/* Function to find the height of the Tree */
int heightOfTree (struct node* root)
{
	if (!root) 		return -1; 	else {
		int l = 1 + heightOfTree (root->left);
		int r = 1 + heightOfTree (root->right);
		return (l > r) ? l : r;
	}
} /* Function to find and return a node in the tree using level order traversal */
struct node* find (struct node* root , int key)
{
	if (!root)
		return NULL;
	struct queue* q = (struct queue*) malloc (sizeof (struct queue));
	q->front = -1; 	q->rear = -1; 	enqueue (q , root);
	while (!isEmptyQueue (q)) {
		root = dequeue (q);
		if (root->id == key)
			return root;
		if (root->left)
			enqueue (q , root->left);
		if (root->right)
			enqueue (q , root->right);
	} 	free (q); 	return NULL;
} /* Function to insert a new employee node in the tree */
void insert (struct node** root , int parent , int child)
{
	struct node* newnode = (struct node*) malloc (sizeof (struct node));
	newnode->id = child; 	newnode->left = NULL;
	newnode->right = NULL; 	if (!(*root)) { *root = newnode; 	 	(*root)->parent = NULL; }
	else {
		struct node* temp = find (*root , parent);
		if (temp) {
			if (!temp->left)
				temp->left = newnode;
			else if (!temp->right)
				temp->right = newnode;
			newnode->parent = temp;
		}
	}
} /* Function to find and return trainers in the tree using level order traversal */ 
int findTrainers (struct node* root , int k , bool trainers[])
{
	int height = heightOfTree (root);
	if (k > height)
		return -1;
	struct queue* q = (struct queue*) malloc (sizeof (struct queue));
	q->front = -1; 	q->rear = -1; 	enqueue (q , root);
	while (!isEmptyQueue (q)) {
		root = dequeue (q); 		struct node* parent = root;
		for (int i = 0; i < k; i++) { parent = parent->parent; 			if (!parent) 				break; }
		if (parent) { trainers[parent->id] = true; }
		if (root->left) 			enqueue (q , root->left);
		if (root->right) 			enqueue (q , root->right);
	} 	free (q); 	return 1;
}  int main ()
{
	int n , k; 	/* To read no.of employees and k value */
	scanf ("%d %d" , &n , &k); 	/* To creata an empty binary Tree */
	struct node* root = NULL; 	/* Insert first emplyee node (Martha) in the tree as root */
	insert (&root , -1 , 1); 	int parent , child; 	/* To read and insert remaining employees and their parent employees in the tree */
	for (int i = 0; i < n - 1; i++) {
		scanf ("%d %d" , &parent , &child);
		insert (&root , parent , child);
	} 	/* Boolean array to store the whether an employee is a trainer or not */
	bool trainers[n + 1]; 	for (int i = 1; i <= n; i++)
		trainers[i] = false; 	/* To find all the trainers */
	int status = findTrainers (root , k , trainers);
	printf ("\nOUTPUT: \n");  /* PLESE REMOVE THIS LINE */ 	/* To print the output */
	if (status == -1)  		printf ("-1"); 	else {
		for (int i = 1; i <= n; i++) {
			if (trainers[i])
				printf ("%d " , i);
		}
	}  	printf ("\n"); /* PLESE REMOVE THIS LINE */
}
