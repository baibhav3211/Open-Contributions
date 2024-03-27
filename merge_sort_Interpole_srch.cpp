#include <iostream>
using namespace std;
int interpolationSearch(int arr[], int l, int h, int ele)
{
    int pos;
    if (l <= h && ele >= arr[l] && ele <= arr[h])
    {
        pos = l+((double(h - l) / (arr[h] - arr[l]))*(ele - arr[l]));
        if (arr[pos] == ele)
            return pos;
        if (arr[pos] < ele)
            return interpolationSearch(arr, pos + 1, h, ele);
        if (arr[pos] > ele)
            return interpolationSearch(arr, l, pos - 1, ele);
    }
    return -1;
}
void printArray(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, *B=new int[high+1];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high)
{
    int mid;
    if(low<high)
    {
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    int A[] = {9, 14, 4, 8, 7, 5, 6, 4, 5, 3};
    printArray(A, sizeof(A)/sizeof(int));
    mergeSort(A, 0, sizeof(A)/sizeof(int)-1);
    int src=interpolationSearch(A,0,9,5);
    cout<<"element 5 is at "<<src<<endl;
    printArray(A, sizeof(A)/sizeof(int));
    return 0;
}
