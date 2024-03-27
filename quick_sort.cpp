#include <iostream>
using namespace std;

void printArray(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}

int main()
{
    int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int B[] = {9, 4, 4, 8, 7, 5, 6};
    printArray(A, sizeof(A)/sizeof(int));
    quickSort(A, 0, sizeof(A)/sizeof(int) - 1);
    printArray(A, sizeof(A)/sizeof(int));
    printArray(B, sizeof(B)/sizeof(int));
    quickSort(B, 0, sizeof(B)/sizeof(int) - 1);
    printArray(B, sizeof(B)/sizeof(int));
    return 0;
}
