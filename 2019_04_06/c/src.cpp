#include <bits/stdc++.h>
using namespace std;

int main(){
  // start process
  vector<long> inp(6);
  for(int i=0; i<6; i++){
    cin >> inp[i];
  }
  vector<long> city(5);
  city[0] = inp[0];
  long time = 1;
  while(1){
    for(int i=4; i>=0; i--){
      if(city[i-1]-inp[i] >= 0){
        city[i-1] -= inp[i];
        city[i] += inp[i];
      }else{
        city[i] += city[i-1];
        city[i-1] = 0;
      }
    }
    time ++;
    if(city[4] == inp[0]){
      cout << time << endl;
      break;
    }
  }
  // end process
  return 0;
}
