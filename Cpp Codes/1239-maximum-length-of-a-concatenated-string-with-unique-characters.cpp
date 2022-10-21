class Solution {
public:
    int maxLength(vector<string>& arr) {
       string s="";
       return recurse(arr,0,s);
    }
    int recurse(vector<string> &arr,int idx,string s)
    {
        if(idx==arr.size()) return s.length();
        string s1=arr[idx];
        bool duplicate=false;
        set<char> st;
        for(int i=0;i<s1.length();i++)
        {
            if(st.find(s1[i])!=st.end()) duplicate=true;
            st.insert(s1[i]);
        }
        if(duplicate) return recurse(arr,idx+1,s);
        else
        {
            st.clear();
            for(int i=0;i<s.length();i++)
            {
                st.insert(s[i]);
            }
            bool found=false;
            for(int i=0;i<s1.length();i++)
            {
                if(st.find(s1[i])!=st.end()) found=true;
            }
            if(found) return recurse(arr,idx+1,s);
            else
            {
                return max(recurse(arr,idx+1,s),recurse(arr,idx+1,s+s1));
            }
            
            
        }
        return 0;
    }
};
