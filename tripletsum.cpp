#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tripletSum(vector<int> arr, int targetSum){
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> ans;
    for(int i=0;i<=n-3;i++){
        int j=i+1;
        int k=n-1;
        while(j<k){
            int currentSum = arr[i];
            currentSum+=arr[j];
            currentSum+=arr[k];

            if(currentSum == targetSum){
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            }else if(currentSum > targetSum){
                k--;
            }else{
                j++;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,6,5,7,4,8};
    int sum = 18;
    auto p = tripletSum(arr, sum);
    for(auto v : p){
        for(auto n: v){
            cout<<n<<",";
        }
        cout<<endl;
    }
    return 0;
}