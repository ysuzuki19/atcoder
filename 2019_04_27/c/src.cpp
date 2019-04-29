#include <bits/stdc++.h>
using namespace std;

int gcd(int m, int n){
  if( (0==m) || (0==n) )
    return 0;
  while(m!=n){
    if(m>n) m = m - n;
    else    n = n - m;
  }
  return m;
}

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int i, j;
  for(i=0; i<n; i++)cin >> a[i];

  vector<int> ccd(n);
  ccd[0] = gcd(a[1], a[2]);
  for(i=0; i<n; i++){
    if(i!=j){
      ccd[j] = gcd(ccd[j], a[i]);
    }
  }
  ccd[1] = gcd(a[0], a[2]);
  for(j=1; j<n; j++){
    for(i=0; i<n; i++){
      if(i!=j){
        ccd[j] = gcd(ccd[j], a[i]);
      }
    }
    ccd[j+1] = gcd(a[0], a[1]);
  }

  int max=a[0];
  for(i=1; i<n; i++){
    max = gcd(max, a[i]);
  }
  for(i=0; i<n; i++){
    if(max<ccd[i]){
      max = ccd[i];
    }
  }
  cout << max << endl;


  return 0;
}
