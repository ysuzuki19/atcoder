#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int pat = 0;
  int aStt = ( x - 100*b - 50*c ) / 500;
  if(aStt<0){
    aStt = 0;
  }
  for(int aIdx=aStt; aIdx<a+1; aIdx++){
    int aTemp = 500*aIdx;
    if(aTemp > x){
      break;
    }
    int bStt = ( x - 500*aIdx - 50*c ) / 100;
    if(bStt < 0){
      bStt = 0;
    }
    for(int bIdx=bStt; bIdx<b+1; bIdx++){
      int bTemp = aTemp + 100*bIdx;
      if(bTemp > x){
        break;
      }
      if((x-bTemp)<=50*c){
        pat++;
      }
    }
  }
  cout << pat << endl;
  return 0;
}
