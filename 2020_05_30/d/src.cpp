#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <list>
using namespace std;

// fold {
#define debug(var)  do{ std::cout << #var << " : "; view(var); }while(0)
using ll = long long;
using ld = long double;
inline int num (const std::string& S, int idx) noexcept { return S.at(idx) - '0'; }
inline int ctoi(char c) noexcept { return c - '0'; }
inline bool isNumber(char c) noexcept { return ('0'<c && c<'9'? true : false); }
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
template<typename T> void view(T e) noexcept { cout << e; }
template<typename T> void view(std::vector<T> v) noexcept { for(const auto& e : v) cout << e << " "; }
template<typename T> void view(std::vector<std::vector<T>> vv) noexcept { for(const auto& v : vv) view(v); }
// }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> v(n);
	vector<int> desire(n);
	list<int> nons;
	for(int i=0; i<v.size(); ++i){
		cin >> v[i];
		if( v[i] != -1 ) desire[v[i]]++;
		else nons.push_back(i+1);
	}
	int default_route = 0;
	for(const auto& e : v){
		if( e != -1 ) default_route++;
		if(v[e] == e) default_route--;
	}
	unsigned long long pattern = 0;
	for(const auto& no : nons){
		for( int i=0; i<v.size(); ++i){
			if( i==no ) continue;
			int routes = default_route;
			pattern += routes;
		}
	}
	cout << pattern << endl;
	return 0;
}
