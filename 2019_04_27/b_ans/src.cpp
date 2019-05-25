#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> c(n), v(n);
  int i;
  for(i=0; i<n; i++)cin >> v[i];
  for(i=0; i<n; i++)cin >> c[i];
  int cp = 0;
  for(i=0; i<n; i++)
    if(v[i]-c[i] > 0)
      cp += v[i] - c[i];
  cout << cp << endl;
  return 0;
}
