#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int *arr, int n)
{
    // Write your code here
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else if (arr[i] == 2)
            count2++;
    }
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) <= count0)
            arr[i] = 0;
        else if ((i + 1) <= (count1 + count0))
            arr[i] = 1;
        else if ((i + 1) <= (count1 + count0 + count2))
            arr[i] = 2;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;

        cin >> size;
        int *arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }

        sort012(arr, size);

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        delete[] arr;
        cout << endl;
    }

    return 0;
}