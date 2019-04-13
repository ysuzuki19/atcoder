#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, y;
  cin >> n >> y;
  int aEnd = y / 10000;
  for(int a=0; a<=aEnd; a++){
    int aTemp = y - 10000*a;
    int bEnd = aTemp / 5000;
    for(int b=0; b<=bEnd; b++){
      int c = (aTemp - 5000*b)/1000;
      if(a + b + c == n){
        cout << a << " " << b << " " << c << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
  return 0;
}
