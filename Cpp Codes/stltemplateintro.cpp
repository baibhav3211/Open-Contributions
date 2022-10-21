#include<iostream>
#include <algorithm>
#define int long long
using namespace std;
int32_t main()
{
	int t, i;
	cin >> t;
	while (t--)
	{
		int n, f, c = 0;
		cin >> n;
		int a[n];
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int p[n];
		for (i = 0; i < n; i++)
			a[i] = i + 1;
		sort(a, a + n);
		i = 0;
		while (1)
		{
			f = 0;
			for (; i < n; i++)
			{
				if (a[i] < p[i])
				{
					f = 1;
					a[i]++;
					c++;
					break;
				}
			}
			if (f == 0)
			{
				if (c % 2 == 0)
					cout << "Second\n";
				else
					cout << "First\n";
				break;
			}
		}

	}

}