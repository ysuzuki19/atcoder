#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> chumon(5);
  for(int i=0; i<chumon.size(); i++){
    cin >> chumon[i];
  }
  int minTemp = chumon[0]%10;
  for(int i=1; i<chumon.size(); i++){
    if(minTemp > chumon[i]%10 && chumon[i]%10 != 0){
      minTemp = chumon[i]%10;
    }
  }
  int sumTime = 0;
  for(int i=0; i<chumon.size(); i++){
    sumTime += chumon[i];
    if(sumTime%10 != 0){
      sumTime += (10 - sumTime%10);
    }
  }
  if(minTemp == 0){
    cout << sumTime << endl;
  }else{
    sumTime -= (10 - minTemp);
    cout << sumTime << endl;
  }
  return 0;
}
