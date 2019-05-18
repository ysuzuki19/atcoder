#include <bits/stdc++.h>
using namespace std;

int main(){
  long i;
  long N;
  cin >> N;
  unsigned long long sum=0;
//  for(i=2; i<N/2; i++){
  for(i=2; i<N; i++){
    if(N/i == N%i){
      sum += i;
//      cout << "CLEAR : ";
//      cout << i << endl;
    }
//      cout << i << " " << N/i << " " << N%i << endl;
  }
  cout << endl;
//  sum += N-1;
  cout << sum << endl;
  return 0;
}
