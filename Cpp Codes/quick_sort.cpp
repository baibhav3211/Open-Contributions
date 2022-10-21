#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int n)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[0] > a[i])
        {
            flag++;
        }
    }

    int temp = a[0];
    a[0] = a[flag];
    a[flag] = temp;

    for (int i = 0, j = n - 1; i < j;)
    {
        if (a[i] < a[flag])
        {
            i++;
        }
        else if (a[j] >= a[flag])
        {
            j--;
        }
        else
        {
            int value = a[i];
            a[i] = a[j];
            a[j] = value;
        }
    }

    return flag;
}

void quickSort(int input[], int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    int c = partition(input, n);

    quickSort(input, c);
    quickSort(input + c+1, n - c-1);
}

int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}
