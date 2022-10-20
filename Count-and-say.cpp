class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";
        }
        vector<string> res(n);
        res[0]="1";
        for(int i=1;i<n;i++)
        {
            string s=res[i-1];
            string temp="";
            int count=1;
            for(int j=1;j<s.length();j++)
            {
                if(s[j]!=s[j-1])
                {
                    char x=count+'0';
                    cout<<x<<endl;
                    temp+=x;
                    temp+=s[j-1];
                    count=1;
                }
                else
                {
                    count++;
                }
            }
            char x=count+'0';
            temp+=x;
            temp+=s[s.length()-1];
            count=1;
            res[i]=temp;
        }
        return res[n-1];
        
    }
};
