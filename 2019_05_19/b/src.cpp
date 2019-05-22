#include <bits/stdc++.h>
using namespace std;

int main(){
  int i, j;
  string str;
  cin >> str;
  int kami = stoi(str.substr(0, 2));
  int simo = stoi(str.substr(2, 2));
  if(kami > 12 || kami==0){
    if(simo > 12 || simo==0){
      cout << "NA" << endl;
      return 0;
    }
    cout << "YYMM" << endl;
    return 0;
  }
  if(simo > 12 || simo==0){
    if(kami > 12 || kami==0){
      cout << "NY" << endl;
      return 0;
    }
    cout << "MMYY" << endl;
    return 0;
  }
  cout << "AMBIGUOUS" << endl;
  return 0;
}
