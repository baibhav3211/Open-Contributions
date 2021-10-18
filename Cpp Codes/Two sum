class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr;
        unordered_map<int, int> mpp;
        for(int i=0; i< nums.size(); i++){
            if(mpp.find(target-nums[i]) != mpp.end()){
                arr.push_back(i);
                arr.push_back(mpp[target-nums[i]]);
            }
            else
                mpp.insert({nums[i],i});
        }
        return arr;
    }
};
