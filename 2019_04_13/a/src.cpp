#include <bits/stdc++.h>
using namespace std;

int main(){
  // start process
  int a, b;
  cin >> a >> b;
  int dif = a - b;
  if(dif==0){
    cout << a + b << endl;
  }else if(dif==1){
    cout << a + a - 1 << endl;
  }else if(dif==-1){
    cout << b + b - 1 << endl;
  }else if(dif>1){
    cout << a + a - 1 << endl;
  }else{
    cout << b + b - 1 << endl;
  }
  // end process
  return 0;
}
