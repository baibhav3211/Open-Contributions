#include<bits/stdc++.h>
using namespace std;


  vector <int> calculateSpan(int p[], int n)
  {
     vector<int> v;
     stack<pair<int,int>> st;
     for(int i=0;i<n;i++)
     {
         while(!st.empty() && p[i]>=st.top().second)st.pop();
         
         if(st.empty())v.push_back(i+1);
         else
         {
             int t=i-st.top().first;
             v.push_back(t);
         }
         st.push({i,p[i]});
     }
     return v;
  }


int main()
{

		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		vector <int> s = calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
		
		return 0;
}

// Input : 
// 7
// 100 80 60 70 60 75 85

// Output :
// 1 1 1 2 1 4 6 




