#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <list>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#define debug(var)  do{ std::cout << #var << " : "; view(var); }while(0)
using ll = long long;
using ld = long double;
inline int num (const std::string& S, int idx) noexcept { return S.at(idx) - '0'; }
inline int ctoi(char c) noexcept { return c - '0'; }
inline bool isNumber(char c) noexcept { return ('0'<=c && c<='9'? true : false); }
inline int safeCtoi(char c) { if(isNumber(c)) { return ctoi(c); } else { throw 1; } }
inline char itoc(int i) noexcept { return i + '0'; }
inline unsigned int bitMask(int i) noexcept { return (1 << i); }
inline bool isTrue(unsigned int bit, int i) noexcept { return bit & bitMask(i); }
inline bool isEven(int num) noexcept { return !num%2; }
inline bool isOdd(int num) noexcept { return num%2; }
template<typename T> inline short sgn(T num) noexcept { return (num==0? 0 : (num>0? 1 : -1) ); }
template<typename T> inline bool isZero(T num) noexcept { return (num==0? true : false); }
template<typename T> inline bool isPositive(T num) noexcept { return (num>0? true : false); }
template<typename T> inline bool isNegative(T num) noexcept { return (num<0? true : false); }
template<typename T> void view(T e) noexcept { cout << e << endl; }
template<typename T> void view(std::vector<T> v) noexcept { for(const auto& e : v) cout << e << " "; cout << endl; }
template<typename T> void view(std::vector<std::vector<T>> vv) noexcept { for(const auto& v : vv) view(v); }

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> b(n);

  for (auto& e: a) cin >> e;
  for (auto& e: b) cin >> e;

  int a_max = a[0];
  int b_min = b[0];

  for (int i=1; i<a.size(); ++i) {
    a_max = max(a_max, a[i]);
    b_min = min(b_min, b[i]);
  }
  if (a_max <= b_min) {
    cout << b_min - a_max + 1 << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}
