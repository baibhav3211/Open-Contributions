#include <bits/stdc++.h>
using namespace std;
#define int long long
// class graph{
// 	public:
// 		int cities;
// 		unordered_map<string,list<string>> map;
// 		graph(int cities)
// 		{
// 			this->cities=cities;
// 		}
// 		void addedge(string first,string second)
// 		{
// 			map[first].push_back(second);
// 		}
// }
int32_t main()
{
	int cities;
	cin >> cities;
	unordered_map<string, list<string>> guide_graph;
	unordered_map<string, int> incities;
	string dest_city, req_city;

	string first, second;
	while (cin >> dest_city >> req_city)
	{
		guide_graph[req_city].push_back(dest_city);
		incities[dest_city]++;
		if (incities.find(req_city) == incities.end())
		{
			incities[req_city] = 0;
		}
	}
	queue<string> guide_order;
	for (auto &node : indegree)
	{
		if (guide_order.second == 0)
		{
			guide_order.push(node.first);
		}
	}
	if (guide_order.empty())
	{
		cout << "0" << endl;
	}
	else
	{
		vector<string> ansOrder;
		while (!visitingOrder.empty())
		{
			string node = visitingOrder.front();
			ansOrder.push_back(node);
			visitingOrder.pop();
			for (string location : adjacencyList[node])
			{
				indegree[location]--;
				if (indegree[location] == 0)
				{
					visitingOrder.push(location);
				}
			}
		}
		if (ansOrder.size() != number_of_cities)
		{
			cout << "0" << endl;
		}
		else
		{
			for (string location : ansOrder)
			{
				cout << location << " ";
			}
		}
	}
	cout << "\n";


	return 0;


}