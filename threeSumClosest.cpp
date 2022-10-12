#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mini = INT_MAX;
        int val = INT_MAX;
        for(int i=0;i<n-2;i++){
            int left = i+1, right = n-1;
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(target-sum)<val){
                    val = abs(target-sum);
                    mini = sum;
                }
                if(sum==target){
                    return sum;
                }
                else if(sum > target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return mini;
    }
};
int main() {
	vector<int> nums = {-1,2,1,-4};
	int target = 1;
	Solution obj;
	cout<<obj.threeSumClosest(nums,target)<<endl;
	return 0;
}
