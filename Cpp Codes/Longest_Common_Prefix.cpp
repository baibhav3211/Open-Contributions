/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200

*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        string ans = strs[0];
        for(int i = 1;i < strs.size(); ++i){
            int p = ans.length();
            int q = strs[i].length();
            int common = 0;
            for(int m = 0, n = 0; m < p && n < q; ++m, ++n){
                if(ans[m] == strs[i][n]){
                    ++common;
                }else{
                    break;
                }
            }
            ans = ans.substr(0, common);
            if(ans == ""){
                break;
            }
        }
        return ans;
    }
};
