#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int mergefiles(vector<int> filesSizes){
    priority_queue<int, vector<int>, greater<int> > a;
    for(int i =0;i<filesSizes.size();i++)
    {
        a.push(filesSizes[i]);
    }
    int sum = 0;
    while(a.size() > 1)
    {
        int c  = a.top();
        a.pop();
        int b = a.top();
        a.pop();
        sum = sum + c + b;
        a.push(c+b);
    }
    return sum; 
}

int main(){
  vector<int> a = {8,12,6,4};
  cout << mergefiles(a);
  return 0;
}
