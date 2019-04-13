#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, a, b;
  cin >> n >> a >> b;
  int count = 0;
  int sum = 0;
  for(int i=1; i<=n; i++){
    int temp = i;
    int sumTemp = 0;
    while(temp!=0){
      sumTemp += temp % 10;
      temp /= 10;
    }
    if(a <= sumTemp && sumTemp <= b){
      sum += i;
    }
  }
  cout << sum << endl;
  return 0;
}
