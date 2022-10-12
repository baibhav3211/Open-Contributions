#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
            
        }
        
        for(int i=0;i<nums.size();i++){
            int  t = target - nums[i];
            
            if(mp.find(t)!=mp.end()){
                if(nums[i]==t){
                    if(mp[nums[i]].size()>1){
                        return {mp[nums[i]][0], mp[nums[i]][1]};
                    }
                }
                
                else{
                    return {mp[nums[i]][0], mp[t][0]};
                }
            }
        }
        return {};
    }
};
int main() {
	vector<int> nums = {2,7,11,15};
	int target = 9;
	Solution obj;
	vector<int> ans = obj.twoSum(nums,target);
	cout<<ans[0]<<" "<<ans[1]<<endl;
	return 0;
}
