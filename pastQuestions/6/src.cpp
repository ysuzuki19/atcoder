#include <bits/stdc++.h>
using namespace std;

int main(){
  // start process
  int n;
  vector<int> a(n);
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  int alice = 0;
  int bob = 0;
  for(int i=0; i<n; i+=2){
    alice += a[i];
    bob += a[i+1];
  }
  cout << alice - bob << endl;


  // end process
  return 0;
}
