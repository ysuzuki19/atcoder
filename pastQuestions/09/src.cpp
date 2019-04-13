#include <bits/stdc++.h>
using namespace std;

string str[4] = {"maerd", "remaerd", "esare", "resare"};

int main(){
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  for(int i=0; i< s.size();){
    for(int j=0; j<4; j++){
      if(s.substr(i,str[j].size()) == str[j]){
        i += str[j].size();
        break;
      }
      if(j == 3){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
