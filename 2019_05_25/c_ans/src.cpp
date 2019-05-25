#include <bits/stdc++.h>
using namespace std;
#define _  << ' ' <<;
#define squ(x)  ((x) * (x));
#define VAR_NAME(var)  cout << #var << " : ";
#define debug(var)  VAR_NAME(var); view(var);
#define MAX(v)  *max_element(v.begin(), v.end());
#define MIN(v)  *min_element(v.begin(), v.end());
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
template <class T>
using VVV = vector<vector<vector<T>>>;
template<typename T>
void view(T e){
  cout << e << endl;
}
template<typename T>
void view(vector<T>& v){
  for(const auto& e : v){
    cout << e << " ";
  }
  cout << endl;
}
template<typename T>
void view(const vector<vector<T>>& vv){
  for(const auto& v : vv){
    for(const auto& e : v)
      cout << e << " ";
    cout << endl;
  }
}

int main(){
  int i, j;
  int N, M;
  cin >> N >> M;
  V<int> l(M);
  V<int> r(M);
  for(i=0; i<l.size(); ++i) cin >> l[i] >> r[i];
  int lmax = MAX(l);
  int rmin = MIN(r);
  int dif = rmin - lmax;
  cout << (dif>=0? dif+1 : 0) << endl;
  return 0;
}
