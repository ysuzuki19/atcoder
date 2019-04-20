#include <bits/stdc++.h>
using namespace std;

int main(){
  // start process
  int i;
  int N;
  cin >> N;
  string S;
  cin >> S;
  int br = 0, wh = 0;
  for(i=0; i<N; i++){
    if(S[i] == '.'){
      wh++;
    }else{
      br++;
    }
  }
  if(wh>br)cout << br << endl;
  else cout << wh << endl;


  // end process
  return 0;
}
