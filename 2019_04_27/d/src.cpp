#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int i, j;
  for(i=0; i<n; i++)cin >> a[i];
  long long tmp=a[1]-a[0];
  for(i=1; i<n-1; i++){
    if(tmp>a[i+1]+a[i]){
      tmp = a[i+1]+a[i];
    }
  }
  cout << tmp << endl;
  tmp *= -2;
  for(i=0; i<n; i++)
    tmp += a[i];
  cout << tmp << endl;


  return 0;
}
