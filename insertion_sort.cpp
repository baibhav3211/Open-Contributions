#include <iostream>
using namespace std;
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
void insertion_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        cout << arr[i] << "p" << endl;
        while(key < arr[j] && j >= 0)
        {
            cout << arr[j] << "in" << endl;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int A[] = {9, 1, 4, 14, 4, 15, 1, 6};
    printArray(A, sizeof(A) / sizeof(int));
    insertion_sort(A, sizeof(A) / sizeof(int));
    printArray(A, sizeof(A) / sizeof(int));
    return 0;
}