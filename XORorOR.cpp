#include <iostream>
#include <map>
#include <vector>
#define int long long
using namespace std;
int32_t main()
{
	int n;
	cin >> n;
	map<pair<string, string>, vector<int>> m;
	for (int i = 0; i < n; i++)
	{
		string f, l;
		int c;
		cin >> f >> l >> c;
		for (int j = 0; j < c; j++)
		{
			int x;
			cin >> x;
			m[ {f, l}].push_back(x);
		}
	}
	for (auto &pr : m)
	{
		auto &full_name = pr.first;
		auto &list = pr.second;
		cout << full_name.first << " " << full_name.second << " ";
		cout << list.size() << endl;
		for (auto &v : list)
		{
			cout << v << " ";
		}
		cout << endl;
	}
	return 0;
}


