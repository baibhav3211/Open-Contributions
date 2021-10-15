#include <iostream>
using namespace std;

void rotate(int arr[], int n)
{
    int temp1 = arr[n - 1], temp2;

    for (int i = 0; i < n; ++i)
    {
        temp2 = arr[i];
        arr[i] = temp1;
        temp1 = temp2;
    }
}

int main()
{

    int a[] = {1, 2, 3, 4, 5};
    rotate(a, 5);
    for (int i = 0; i < 5; ++i)
        cout << a[i] << ", ";

    return 0;
}