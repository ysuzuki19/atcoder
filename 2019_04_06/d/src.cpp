#include <bits/stdc++.h>
using namespace std;

int main(){
  // start process
  vector<int> s(3);
  int k;
  cin >> s[0] >> s[1] >> s[2] >> k;

  vector<vector<int> > taste(3);
  for(int i=0; i<taste.size(); i++){
    taste[i].resize(s[i]);
    for(int j=0; j<s[i]; j++){
      cin >> taste[i][j];
    }
    sort(taste[i].begin(),taste[i].end(),greater<int>());
  }








  int k_taste = 0;
  cout << k_taste << endl;


  // end process
  return 0;

