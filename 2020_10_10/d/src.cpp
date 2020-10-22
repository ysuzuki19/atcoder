#include <iostream>
#include <string>
#include <vector>
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

	size_t t;
	cin >> t;

	auto contain = [] (size_t a, size_t b) {
		return a - b + 1;
	};
	auto convolution = [] (size_t a, size_t b) {
		return (a + b - 1);
	};

	for (size_t i=0; i<t; ++i) {
		size_t n, a, b;
		cin >> n >> a >> b;

		if (a<b) swap(a, b);

		size_t a_pat = contain(n,a) * contain(n,a);
		size_t b_pat = contain(n,b) * contain(n,b);
		size_t ab_conv = a_pat * convolution(a,b) * convolution(a,b);
		size_t ab_excl = 4 * contain(n,a) * (convolution(a,b)*convolution(a,b)*3/4);
		//cout << a_pat << " " << b_pat << " " << conv << endl;
		//debug(n);
		//debug(a_pat);
		//debug(b_pat);
		//debug(conv);

		cout << a_pat * b_pat + ab_excl - ab_conv << endl;
	}

	return 0;
}
