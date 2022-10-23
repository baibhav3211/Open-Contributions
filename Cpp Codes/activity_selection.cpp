#include <bits/stdc++.h>
using namespace std;

void sortActivity(int s[], int f[], int n)
{
    pair<int, int> sortedpair[n];

    for (int i = 0; i < n; i++)
    {
        sortedpair[i].first = f[i];
        sortedpair[i].second = s[i];
    }

    sort(sortedpair, sortedpair + n);

    for (int i = 0; i < n; i++)
    {
        f[i] = sortedpair[i].first;
        s[i] = sortedpair[i].second;
    }
}

void activity(int s[], int f[], int n)
{
    int sol[n];
    int j = 0, k = 0;
    sol[k] = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] >= f[j])
        {
            sol[++k] = i;
            j = i;
        }
    }
    for (int i = 0; i <= k; i++)
        cout << s[sol[i]] << " ";
    cout << endl;
    for (int i = 0; i <= k; i++)
        cout << f[sol[i]] << " ";
}

int main()
{
    int s[] = {3, 5, 0, 8, 1, 5};
    int f[] = {4, 7, 6, 9, 2, 9};
    int n = 6;
    sortActivity(s, f, n);
    activity(s, f, n);
    return 0;
}