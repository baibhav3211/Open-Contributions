#include <iostream>
#include <map>
#include <set>
#define int long long
using namespace std;
int32_t main()
{
	int n;
	cin >> n;
	map<int, multiset<string>> m;
	for (int i = 0; i < n; i++)
	{
		int x;
		string name;
		cin >> name >> x;
		m[-1 * x].insert(name);
	}
	for (auto &marks_student_pr : m)
	{
		auto &name = marks_student_pr.second;
		auto &marks = marks_student_pr.first;
		for (auto student : name)
		{
			cout << student << " " << -1 * marks << endl;
		}
	}
	return 0;
}