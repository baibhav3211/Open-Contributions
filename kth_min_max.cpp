// Find kth min and max element in an array

#include <iostream>
#include <algorithm>
using namespace std;

void kthMaxMin(int a[], int size, int k)
{

    sort(a, a + size);

    cout << "kth Max : " << a[size - k] << endl;
    cout << "kth Min : " << a[k - 1] << endl;
}

int main()
{
    int a[] = {1, 6, 3, 4, 5, 2};

    kthMaxMin(a, 6, 2);

    return 0;
}