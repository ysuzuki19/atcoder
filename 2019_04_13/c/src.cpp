#include <bits/stdc++.h>
using namespace std;

int main(){
  // start process
  string s;
  int i,j;
  cin >> s;
  int even = 0, odd = 0;
  for(i=0; i<s.length(); i++){
    if(s[i]=='0'){
      if(i%2==0){
        even++;
      }else{
        odd++;
      }
    }
  }
  int change = 0;
  if(even>odd){
    for(i=0; i<s.length(); i++){
      if(i%2==0){
        if(s[i]!='0'){
          change++;
        }
      }else{
        if(s[i]=='0'){
          change++;
        }
      }
    }
  }else{
    for(i=0; i<s.length(); i++){
      if(i%2==0){
        if(s[i]=='0'){
          change++;
        }
      }else{
        if(s[i]!='0'){
          change++;
        }
      }
    }
  }
  cout << change << endl;
  // end process
  return 0;
}
