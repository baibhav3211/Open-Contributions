#include <bits/stdc++.h>
using namespace std;
class Node {
public:
	int data;
	Node* next;
	Node* child;
};
Node* createList(int* arr, int n)
{
	Node* head = NULL;
	Node* tmp;
	for (int i = 0; i < n; i++) {
		if (head == NULL) {
			tmp = head = new Node();
		}
		else {
			tmp->next = new Node();
			tmp = tmp->next;
		}
		tmp->data = arr[i];
		tmp->next = tmp->child = NULL;
	}
	return head;
}
void printMultiLevelList(Node* head)
{
	while (head) {
		if (head->child) {
			printMultiLevelList(head->child);
		}
		cout << head->data << " ";
		head = head->next;
	}
}
int main()
{
	int arr1[3] = { 1, 2, 3 };
	int arr2[2] = { 5, 6 };
	int arr3[1] = { 4 };
	int arr4[3] = { 7, 8, 9 };
	Node* head1 = createList(arr1, 3);
	Node* head2 = createList(arr2, 2);
	Node* head3 = createList(arr3, 1);
	Node* head4 = createList(arr4, 3);
	head1->child = head2;
	head1->next->next->child = head3;
	head2->next->child = head4;
	Node* head = NULL;
	head = head1;
	printMultiLevelList(head);

	return 0;
}
