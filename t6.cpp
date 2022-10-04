#include <bits/stdc++.h>
using namespace std;

#define int long long
// Find all binary strings that can be formed from a given wildcard pattern
void printAllCombinations(string pattern, int i)
{
	if (pattern[i] == '\0')
	{
		cout << pattern << endl;
		return;
	}

	// if the current character is '?'
	if (pattern[i] == '?')
	{
		for (int k = 0; k < 2; k++)
		{
			// replace '?' with 0 and 1
			pattern[i] = k + '0';

			// recur for the remaining pattern
			printAllCombinations(pattern, i + 1);

			// backtrack (since the array is passed by reference to the function)
			pattern[i] = '?';
		}
		return;
	}

	// if the current character is 0 or 1, ignore it and
	// recur for the remaining pattern
	printAllCombinations(pattern, i + 1);
}

int32_t main()
{
	// char pattern[] = "11100??11";
	char pattern[101];
	gets(pattern);

	printAllCombinations(pattern, 0);

	return 0;
}