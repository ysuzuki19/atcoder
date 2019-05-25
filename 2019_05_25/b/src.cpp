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
//// view vector functions
template<typename T>
void view(T e){
  cout << e << endl;
}
template<typename T>
void view(vector<T>& v){
  for(const auto& e : v){
    cout << setw(5)<< e << " ";
  }
  cout << endl;
}

template<typename T>
void view(const vector<vector<T>>& vv){
  for(const auto& v : vv){
    for(const auto& e : v)
      cout << setw(5) << e << " ";
    cout << endl;
  }
}

int main(){
  int i, j;
  int R, D;
  cin >> R >> D;
  V<int> x(11);
  cin >> x[0];
  for(i=1; i<x.size(); ++i){
    x[i] = R*x[i-1] - D;
  }
  for(i=1; i<x.size(); ++i){
    cout << to_string(x[i]) << endl;
  }
  return 0;
}
