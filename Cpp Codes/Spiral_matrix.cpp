//print matrix in spiral form.
#include<iostream>
#include<vector>
using namespace std;
void print(vector<vector<int>>&a)
{
  for(int i=0;i<a.size();i++)
  {
      for(int j=0;j<a[i].size();j++)
      {
          cout<<a[i][j]<<" ";
      }
       cout<<endl;
  }  
 
}
void spiral(vector<vector<int>>&a)
{
    int top,bottom,right,left;
    top=0;
    left=0;
    right=a[0].size()-1;
    bottom=a.size()-1;
    while (top<=bottom  && left<=right)
    {
        for(int i=left;i<=right;i++)
        {
            cout<<a[top][i]<<" ";
        }
        top++;
        for(int i=top;i<=bottom;i++)
        {
            cout<<a[i][right]<<" ";
        }
        right--;
        if(top<=bottom)
        {
            for(int i=right;i>=left;i--)
            {
                cout<<a[bottom][i]<<" ";
            }
            bottom--;
        }
        if(left<=right)
        {
            for(int i=bottom;i>=top;i--)
            {
                cout<<a[i][left]<<" ";
            }
            left++;
        }
    }
    
}

int main()
{
vector<vector<int>>a={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
 print(a);
spiral(a);
return 0;
}