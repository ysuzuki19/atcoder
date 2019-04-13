#include <bits/stdc++.h>
using namespace std;

int main(){
  string str;
  cin >> str;
  int count;
  for(int i=0; i<str.length(); i++){
    if(str[i] == '1'){
      count ++;
    }
  }
  cout << count << endl;
  return 0;
}
