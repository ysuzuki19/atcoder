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

int closest(set<int> const& st, int query) {
  const auto itr = st.lower_bound(query);
  if (itr == st.begin()) {
    return *itr;
  }
  const auto prev_itr = std::prev(itr);
  return (itr == st.end() || query - *prev_itr <= *itr - query) ? *prev_itr: *itr;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(M);

  for (auto& a: A) cin >> a;
  for (auto& b: B) cin >> b;

  set<int> st;
  for (const auto& a: A) {
    st.insert(a);
  }

  int min_diff = abs(A[0] - B[0]);
  for (const auto &b : B)
  {
    int cl = closest(st, b);
    min_diff = min(min_diff, abs(cl - b));
  }
  cout << min_diff << endl;

  return 0;
}
