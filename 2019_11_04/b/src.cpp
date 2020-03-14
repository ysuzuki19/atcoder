#include <bits/stdc++.h>
#define _ << ' ' <<
#define _squ(x)  ((x) * (x))
#define debug(var)  do{std::cerr << #var << " : "; view(var);}while(0)
#define line_debug(var)  do{std::cerr << "l" << __LINE__ << " " << #var << " : "; view(var);}while(0)
#define _max(v)  *max_element(v.begin(), v.end())
#define _min(v)  *min_element(v.begin(), v.end())
#define _sort(var)  std::sort(var.begin(), var.end());
#define _rsort(var)  std::sort(var.begin(), var.end(), std::greater<>());
using namespace std;
using ll = long long;
int gcd(int m, int n){return !n ? m : gcd(n, m%n);}
template<typename T> using V = std::vector<T>;
template<typename T> using VV = std::vector<std::vector<T>>;
template<typename T> using VVV = std::vector<std::vector<std::vector<T>>>;
template<typename T> void view(const T e){ std::cerr << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){ for(const auto& e : v) std::cerr << e << " "; std::cerr << std::endl; }
template<typename T> void view(const std::vector<std::vector<T>>& vv){ for(const auto& v : vv){ view(v); } }

//void to_bin (vector<bool>& conb, int deci){
//  for(size_t i=0; i<conb.size(); ++i){
//    if(deci%2==0) conb[i] = 0;
//    else conb[i] = 1;
//    deci /= 2;
//  }
//}

int main(){
  int i, j;
  int N;
  cin >> N;
  vector<pair<int, int>> pairs(N);
  for(i=0; i<N; ++i) cin >> pairs[i].first >> pairs[i].second;
  sort(pairs.begin(), pairs.end());
  int lower = INT_MAX;
  long long max_funny = 0;
  for(i=1; i<N; ++i){
    long long temp_funny = 0;
    lower = pairs[0].second;
    for(j=1; j<i; ++j){
      lower = min(lower, pairs[j].second);
    }
    long long temp = lower - pairs[i-1].first;
    temp_funny = (temp>0? temp : 0);
    lower = pairs[i].second;
    for(j=i+1; j<N; ++j){
      lower = min(lower, pairs[j].second);
    }
    temp = lower - pairs[N-1].first;
    temp_funny += (temp>0? temp : 0);
    max_funny = max(max_funny, temp_funny+2);
  }
//  for(const auto& e : pairs) cout << e.first << " " << e.second << "  ";
//  cout << endl;
  cout << max_funny << endl;


  /*
  V<int> l(N);
  V<int> r(N);
  int upper = 0;
  int lower = INT_MAX;
  for(i=0; i<l.size(); i++) cin >> l[i] >> r[i];
  unsigned long long max_funny = 0;
  unsigned long long deci = 0;
  vector<bool> conb(N);
  for(unsigned long long i=0; i<N*N; ++i){
    to_bin(conb, deci);
    deci++;
    upper = 0;
    lower = INT_MAX;
    for(unsigned long long i=0; i<conb.size(); ++i){
      if(conb[i]){
        upper = max(upper, l[i]);
        lower = min(lower, r[i]);
      }
    }
    if(upper==0 && lower==INT_MAX) continue;
    unsigned long long funny_temp = 0;
    if(lower>upper) funny_temp = lower - upper + 1;
    upper = 0;
    lower = INT_MAX;
    for(int i=0; i<conb.size(); ++i){
      if(!conb[i]){
        upper = max(upper, l[i]);
        lower = min(lower, r[i]);
      }
    }
    if(upper==0 && lower==INT_MAX) continue;
    if(lower>upper) funny_temp += lower - upper + 1;
    max_funny = max(max_funny, funny_temp);
  }
  cout << max_funny << endl;
  */
  return 0;
}
