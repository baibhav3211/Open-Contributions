#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int counter = 0;
    int recordbreak = A[0];
    if (n == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (A[i] > recordbreak)
        {
            counter++;
            recordbreak = A[i];
        }
    }
    cout << counter << endl;
    return 0;
}