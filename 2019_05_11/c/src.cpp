#include <bits/stdc++.h>
using namespace std;

int main(){
  int i, j;
  int N;
  cin >> N;
  int incAB=0, topB=0, endA=0;
  string temp;
  for(i=0; i<N; i++){
    cin >> temp;
    for(j=0; j<temp.size()-1; j++){
      if(temp.substr(j, 2) == "AB"){
        incAB++;
      }
    }
    if(temp[0]=='B'){
      topB++;
    }
    if(temp[temp.size()-1]=='A'){
      endA++;
    }
  }
//  if(topB==N && endA == N)
  if(topB==endA)
    cout << incAB + min(topB, endA) - 1 << endl;
  else
    cout << incAB + min(topB, endA)  << endl;
  return 0;
}
