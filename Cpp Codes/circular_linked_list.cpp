#include <iostream>

using namespace std;

struct node
{
    int data;
    node *link;
};

node *head = NULL;

void printlist(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    do
    {
        cout << temp->data;
        temp = temp->link;
    } while (temp != head);
}

node *insertbeg_naive(node *head, int d)
{
    node *temp = new node();
    temp->data = d;
    temp->data = NULL;
    if (head == NULL)
    {
        temp->link = temp;
    }
    else
    {
        node *curr = head;
        while (temp->link != head)
        {
            temp = temp->link;
        }
        curr->link = temp;
        temp->link = head;
        return temp;
    }
}

node *insertbeg_eff(node *head, int d)
{
    node *temp = new node();
    temp->data = d;
    temp->data = NULL;
    if (head == NULL)
    {
        temp->link = temp;
    }
    else
    {
        temp->link = head->link;
        head->link = temp; /*inserting at second place*/

        int t = head->data;
        head->data = temp->data;
        temp->data = t; /*swapping the values*/

        return head;
    }
}

node *insetend(node *head, int d)
{
    node *temp = new node();
    temp->data = d;
    temp->link = NULL;
    if (head = NULL)
    {
        temp->link = temp;
        return temp;
    }
    else
    {
        node *curr = head;
        while (curr->link != head)
        {
            curr = curr->link;
        }
        curr->link = temp;
        temp->link = head;
        return head;
    }
    /* we can also do this op in o(1) time only change to insert beg program to change the head pointer */
}

node *deletehead(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->link == head)
    {
        free(head);
        return NULL;
    }
    node *curr = head;
    while (curr != head)
    {
        curr = curr->link;
    }
    curr->link = head->link;
    free(head);
    return (curr->link);
}

node *deletekth_node(int k)
{
    /*if head is null then return null*/
    /*if head is the only element then we can do delete beg call*/
    node *curr = head;
    for (int i = 0; i < k - 2; i++)
    {
        curr = curr->link;
    }
    node *temp = curr->link;
    curr->link = curr->link->link;
    free(temp);
    return head;
}

int main()
{
    return 0;
}
