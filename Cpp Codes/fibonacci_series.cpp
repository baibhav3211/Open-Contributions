#include <iostream>
using namespace std;
int main(){
  int a = 0;
  int b = 1;
  cin >> n;
  if(n == 1)
    cout << "0" << endl;
  else
  {
    cout << "0 ";
    cout << "1 ";
    for(int i = 3;i<=n;i++)
    {
      c = a+b;
      cout << c << " ";
      a = b;
      b =c;
    }
    cout << endl;
  }
  return 0;
}
