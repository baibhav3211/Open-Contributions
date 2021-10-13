#include <iostream>
using namespace std;
//NOw templates are used for converting a given function or class of certain datatype to of any datatype.
/*For example if we want this stack to be of anydatatype not only int we can use template.*/
template <class T>
class stack
{
private:
    T *stk;
    int top;
    int size;

public:
    stack(int sz)
    {
        size = sz;
        top = -1;
        stk = new T[size];
    }
    void push(T x);
    void pop();
};

//For function another template.
template <class T>
//Making our class as template.
void stack<T>::push(T x)
{
    if (top == size - 1)
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        top++;
        stk[top] = x;
        cout << stk[top] << endl;
    }
}

template <class T>
void stack<T>::pop()
{
    T x = 0;
    if (top == -1)
    {
        cout << "Stack is empty can not give output" << endl;
    }
    else
    {
        x = stk[top];
        top--;
    }
    cout << x << endl;
}

int main()
{
    stack<int> s(10);
    s.push(10);
    s.pop();
    s.pop();
    stack<string> s1(10);
    s1.push("Eshan");
    s1.push("VIT");
    s1.pop();
    s1.pop();
    s1.pop();
}