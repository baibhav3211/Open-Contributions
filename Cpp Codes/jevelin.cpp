
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		unordered_map<char, vector<int>> index;
		string s;
		cin >> s;
		string temp = s;
		for (int i = 0; i < s.size(); i++)
			index[s[i]].push_back(i);

		vector<vector<int>> v;
		for (auto i : index)
			v.push_back(i.second);

		sort(v.begin(), v.end(), [](auto a, auto b)
			 { return a.size() > b.size(); });
		auto i = 1;
		auto j = 0;
		int prev = 0, prev1 = 0;
		while (i != v.size() && j != v.size())
		{
			bool curr = false;
			while (prev < v[j].size() && i < v.size())
			{
				curr = false;
				swap(s[v[i][prev1]], s[v[j][prev]]);
				prev++;
				prev1++;
				if (prev1 == v[i].size())
				{
					curr = true;
					i++;
					prev1 = 0;
				}
			}

			j++;
			prev = 0;
		}
		bool flag = false;
		cout << "Case #" + to_string(t + 1) + ": ";
		for (int k = 0; k < s.size(); k++)
		{
			if (s[k] == temp[k])
			{
				{
					flag = true;
					cout << "IMPOSSIBLE";
					break;
				}
			}
		}
		if (!flag)
			cout << s;
		cout << endl;
	}
	
}