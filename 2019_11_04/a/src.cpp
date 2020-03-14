#include <bits/stdc++.h>
#define _ << ' ' <<
#define _squ(x)  ((x) * (x))
#define debug(var)  do{std::cout << #var << " : "; view(var);}while(0)
#define line_debug(var)  do{std::cout << "l" << __LINE__ << " " << #var << " : "; view(var);}while(0)
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
template<typename T> void view(const T e){ std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){ for(const auto& e : v) std::cout << e << " "; std::cout << std::endl; }
template<typename T> void view(const std::vector<std::vector<T>>& vv){ for(const auto& v : vv){ view(v); } }

int souwa ( int inp ) {
  if(inp<=0) return 0;
  size_t wa = 0;
  for(int i=0; i<inp; ++i){
    wa += i;
  }
  return wa;
}

int main(){
  int i, j;
//  int N;
//  cin >> N;
//  V<int> v(N);
//  for(i=0; i<v.size(); i++) cin >> v[i];
  string S;
  cin >> S;
  vector<int> num(S.length()+1, 0);
  int counter = 1;
  for(int i=0; i<num.size(); ++i){
    bool is_larger = (S[i]=='<'? true : false);
    if(is_larger){
      num[i+1] = counter;
      counter++;
    }else{
      counter = 1;
    }
  }
//  debug(num);
  counter = 1;
  for(int i=num.size()-1; i>0; --i){
    bool is_larger = (S[i-1]=='<'? true : false);
    if(!is_larger){
      if(num[i-1] <= counter) num[i-1] = counter;
      counter++;
    }else{
      counter = 1;
    }
  }

//  debug(num);
  unsigned long long sums = 0;
  for(const auto& e : num) sums += e;
  cout << sums << endl;

//  0<3>2>1>0<1<2>0<1<2<3<4<5>2>1>0<1

  return 0;
}
