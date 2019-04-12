#include <bits/stdc++.h>
using namespace std;

int main(){
  // start process
  int n;
  int i;
  cin >> n;
  vector<int> t(n);
  vector<int> x(n);
  vector<int> y(n);
  t[0] = 0;
  x[0] = 0;
  y[0] = 0;
  for(i=1; i<n+1; i++){
    cin >> t[i] >> x[i] >> y[i];
  }
  int pastEO = 0;
  int currEO = 0;
  int timeEO = 0;
  int necessaryMove = 0;
  for(i=1; i<n+1; i++){
    necessaryMove = abs(x[i]-x[i-1]) + abs(y[i]-y[i-1]);
    if(necessaryMove > t[i] - t[i-1]){
      cout << "No" << endl;
      return 0;
    }
    timeEO = (t[i]-t[i-1])%2;
    currEO = (x[i]+y[i])%2;
    if(pastEO == currEO){
      if(timeEO == 0){
      }else{
        cout << "No" << endl;
        return 0;
      }
    }else{
      if(timeEO == 0){
        cout << "No" << endl;
        return 0;
      }else{
      }
    }
    pastEO = currEO;
  }
  cout << "Yes" << endl;
  // end process
  return 0;
}
