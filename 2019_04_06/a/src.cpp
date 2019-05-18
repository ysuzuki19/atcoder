#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> con(5);
  int i,j;
  for(i=0; i<con.size(); i++){
    cin >> con[i];
  }
  int k;
  cin >> k;
  int cantComm = 0;
  for(i=0; i<con.size(); i++){
    for(j=i+1; j<con.size(); j++){
      if(con[j]-con[i] > k){
        cantComm++;
      }
    }
  }
  if(cantComm == 0){
    cout << "Yay!" << endl;
  }else{
    cout << ":(" << endl;
  }
  return 0;
}
