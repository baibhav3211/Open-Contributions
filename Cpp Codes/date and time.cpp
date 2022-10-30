#include <ctime>   
#include <iostream>  
  
  
using namespace std;  
  
int main()  
{  
  
    time_t now = time(0);  
  
    char* dt = ctime(&now); 
  
    cout << "The local date and time is: " << dt << endl; 
  
    tm* gmtm = gmtime(&now);  
    dt = asctime(gmtm);  
    cout << "The UTC date and time is:" << dt << endl;  
}  
