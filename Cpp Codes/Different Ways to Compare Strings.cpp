#include <iostream>  
using namespace std;  
#include <string.h>  
  
int main ()  
{   
    const char *str1 = " Hello sparsh";  
    const char *str2 = " Hello sparsh ";  
      
    const char *str3 = " sparsh";  
    const char *str4 = " sparsh";  
      
    cout << " String 1: " << str1 << endl;  
    cout << " String 2: " << str2 << endl;  
    if (strcmp (str1, str2) == 0)  
    {  
        cout << " \n Both strings are equal. " << endl;  
    }  
    else   
        {  
          
        cout << " The strings are not equal. " << endl;  
    }  
          
    cout << " \n String 3: " << str3 << endl;  
    cout << " String 4: " << str4 << endl;   
    if (strcmp (str3, str4) == 0)  
    {  
        cout << " \n Both strings are equal. " << endl;  
    }     
    else   
        cout << " \n The strings are not equal. ";      
          
return 0;  
}  
