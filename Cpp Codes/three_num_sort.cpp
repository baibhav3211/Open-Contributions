//Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo

#include <iostream>
using namespace std;

void sortArray(int a[], int size)
{
    int i = 0, j = 0, k = size - 1;

    while (j != k)
    {
        while (a[i] == 0)
            ++i;
        while (a[k] == 2)
            --k;
        j = i;
        while (a[j] == 1)
            ++j;

        if (a[j] == 2)
        {
            a[j] = a[k];
            a[k] = 2;
        }
        else if (a[j] == 0)
        {
            a[j] = a[i];
            a[i] = 0;
        }
    }
}

int main()
{
    int a[] = {0, 2, 1, 0, 0, 1, 1, 2, 0, 2, 0};

    sortArray(a, 11);

    for (int i = 0; i < 11; ++i)
    {
        cout << a[i] << ',';
    }

    return 0;
}