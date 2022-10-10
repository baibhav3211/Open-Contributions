/*You are given two strings,  and , separated by a new line. Each string will consist of lower case Latin characters ('a'-'z').

Output Format

In the first line print two space-separated integers, representing the length of  and  respectively.
In the second line print the string produced by concatenating  and  ().
In the third line print two strings separated by a space,  and .  and  are the same as  and , respectively, except that their first characters are swapped.**/


#include <iostream>
#include <string>
using namespace std;

int main() {
	string a,b;
    cin>>a>>b;
    cout<<a.length()<<" "<<b.length();
    string c=a+b;
    cout<<endl<<c;
    string copy_a=a;
    cout<<endl<<a.replace(0,1,b,0,1)<<" "<<b.replace(0,1,copy_a,0,1); 
    return 0;
}
