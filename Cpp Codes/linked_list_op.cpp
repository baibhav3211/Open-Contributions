#include <iostream>

using namespace std;

struct node
{
    int data;
    node *link;
};

node *head = NULL;

void insertbeg(int d)
{
    node *ptr = new node();
    ptr->data = d;
    ptr->link = head;
    head = ptr;
}

void insertend(int d)
{
    node *temp = head;
    node *ptr = new node();
    ptr->data = d;
    ptr->link = NULL;
    if (head == NULL)
    {
        head = ptr;
    }
    else
    {
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = ptr;
    }
}

void deletebeg()
{
    if (head == NULL)
    {
        cout << "empty";
    }
    else
    {
        node *ptr = head;
        head = head->link;
        free(ptr);
    }
}

void deleteend()
{
    if (head == NULL)
    {
        cout << "empty";
    }
    else
    {
        if (head->link == NULL)
        {
            node *ptr = head;
            free(ptr);
        }
        else
        {
            node *ptr, *prev;
            ptr = head;
            while (ptr->link != NULL)
            {
                prev = ptr;
                ptr = ptr->link;
            }
            prev->link = NULL;
            free(ptr);
        }
    }
}

void showlist(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->link;
    }
}

void reverselist()
{
    node *p, *c, *n;
    p = NULL;
    c = head;
    while (c != NULL)
    {
        n = c->link;
        c->link = p;
        p = c;
        c = n;
    }
    head = p;
}

void displaymiddleelement_basic()
{
    node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        i = i + 1;
        temp = temp->link;
    }
    int middle = i / 2 + 1;
    node *display = head;
    for (int j = 0; j < middle - 1; j++)
    {
        display = display->link;
    }
    cout << display->data << endl;
}

void displaymiddleelement_advanced()
{
    node *slow = head;
    node *fast = head;
    if (head == NULL)
    {
        cout << "empty";
    }
    else
    {
        while (fast != NULL && fast->link != NULL)
        {
            slow = slow->link;
            fast = fast->link->link;
        }
        cout << slow->data << endl;
    }
}

int detectloop(node *head)
{
    node *slow, *fast;
    slow = head;
    fast = head;
    while (fast != NULL && fast->link != NULL)
    {
        fast = fast->link->link;
        slow = slow->link;

        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}

void deletenode_givenpointertothatone(node *ptr)
{
    node *temp;
    temp = ptr->link;
    ptr->data = temp->data;
    ptr->link = temp->link;
    free(temp);
}

int main()
{
    insertend(6);
    insertbeg(7);
    insertbeg(9);
    insertend(10);
    insertbeg(11);

    reverselist();

    displaymiddleelement_basic();
    displaymiddleelement_advanced();

    showlist(head);

    int dloop = detectloop(head);
    cout << dloop << endl;
    return 0;
}
