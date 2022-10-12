class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        vector<int> temp=nums;
        int n=nums.size();
        int res1=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]+nums[i-1]>nums[i])
            {
                nums[i]=nums[i]+nums[i-1];
            }
            res1=max(nums[i],res1);
        }
        nums=temp;
        int res2=nums[0];
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]+nums[i-1]<nums[i])
            {
                nums[i]=nums[i]+nums[i-1];
            }
            res2=min(nums[i],res2);
        }
        return max(abs(res1),abs(res2));
        
        
        
    }
};
