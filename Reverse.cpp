#include <iostream>
using namespace std;

void reverse_array(int a[], int size)
{
    int end = size - 1, start = 0;
    while (end > start)
    {
        int temp = a[end];
        a[end] = a[start];
        a[start] = temp;
        ++start;
        --end;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    reverse_array(a, 6);
    for (int i = 0; i < 6; ++i)
        cout << a[i] << endl;
    return 0;
}