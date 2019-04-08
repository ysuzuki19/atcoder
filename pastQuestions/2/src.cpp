#include <bits/stdc++.h>
using namespace std;

int main(){
  // start process
  string str;
  cin >> str;
  int count;
  for(int i=0; i<str.length(); i++){
    if(str[i] == '1'){
      count ++;
    }
  }
  cout << count << endl;
  // end process
  return 0;
}
