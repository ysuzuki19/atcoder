#include <bits/stdc++.h>
using namespace std;

int main(){
  int waitingTime;
  int sumTime = 0;
  int maxTemp = 0;
  for(int i=0; i<5; i++){
    cin >> waitingTime;
    sumTime += (waitingTime+9)/10*10;
    if(waitingTime%10 != 0)
      maxTemp = max(maxTemp, 10-waitingTime%10);
  }
  cout << sumTime - maxTemp << endl;
  return 0;
}
