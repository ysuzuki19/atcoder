#include <bits/stdc++.h>
using namespace std;

int main(){
  int i, j;
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  S[K-1] = S[K-1] + 0x20;
  cout << S << endl;
  return 0;
}
