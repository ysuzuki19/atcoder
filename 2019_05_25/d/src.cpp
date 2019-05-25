#include <bits/stdc++.h>
using namespace std;
#define _  << ' ' <<
#define squ(x)  ((x) * (x))
#define VAR_NAME(var)  std::cout << #var << " : ";
#define debug(var)  VAR_NAME(var); view(var);
#define SORT(var)  std::sort(var.begin(), var.end());
#define RSORT(var)  std::sort(var.begin(), var.end(), std::greater<>());
using ll = long long;
template <class T>
using V = vector<T>;
template <class T>
using VV = vector<vector<T>>;
template <class T>
using VVV = vector<vector<vector<T>>>;
//// view vector functions
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
  V<int> a(N);
  V<int> b(M);
  V<int> c(M);
  for(i=0; i<a.size(); ++i) cin >> a[i];
  for(i=0; i<b.size(); ++i) cin >> b[i] >> c[i];
  for(j=0; j<M; ++j){
    int conv = 0;
    RSORT(a);
    for(i=0; i<N; ++i){
      if(a[i]<c[j]){
        a[i] = c[j];
        conv++;
      }
      if(conv>=b[j]) break;
    }
    debug(a);
  }
  ll sums = 0;
  for(const auto& e : a)sums += e;
  cout << sums << endl;
  return 0;
}
