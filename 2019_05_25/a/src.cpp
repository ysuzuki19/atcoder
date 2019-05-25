#include <bits/stdc++.h>
using namespace std;
#define _  << ' ' <<
#define squ(x)  ((x) * (x))
#define VAR_NAME(var)  cout << #var << " : ";
#define debug(var)  VAR_NAME(var); view(var);
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
template <class T>
using VVV = vector<vector<vector<T>>>;

int main(){
  int i, j;
  int N, K;
//  cin >> N >> K;
  int a, b;
  cin >> a >> b;
  cout << (13<=a? b : (5<a? b/2 : 0)) << endl;
  return 0;
}
