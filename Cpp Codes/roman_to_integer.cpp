class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> ump;
        ump.insert({'I',1});
        ump.insert({'V',5});
        ump.insert({'X',10});
        ump.insert({'L',50});
        ump.insert({'C',100});
        ump.insert({'D',500});
        ump.insert({'M',1000});
        int ans=0;
        if(s.length()==1)
        {
            return ump[s[0]];
        }
        int prev=0;
        int curr=1;
        while(prev<s.length() && curr<s.length())
        {
            if(ump[s[prev]]<ump[s[curr]])
            {
                ans+=(ump[s[curr]]-ump[s[prev]]);
                prev+=2;
                curr+=2;
            }
            else
            {
                ans+=ump[s[prev]];
                prev++;
                curr++;
            }
        }
        if(prev==s.length()-1 && curr==s.length()) ans+=ump[s[prev]];
        return ans;

        
    }
};
