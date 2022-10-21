class Solution {
public:
    int evalRPN(vector<string>& t) {
        stack<int> s;
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=="+")
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int res=a+b;
                s.push(res);
            }
            else if(t[i]=="-")
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int res=b-a;
                s.push(res);
                
            }
            else if(t[i]=="*")
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int res=a*b;
                s.push(res);
                
            }
            else if(t[i]=="/")
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int res=b/a;
                s.push(res);
                
            }
            else
            {
                int p=stoi(t[i]);
                s.push(p);
            }
            cout<<s.top()<<" ";
            
        }
        return s.top();
    }
};
