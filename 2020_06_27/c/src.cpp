#include <iostream>
#include <string>
#include <vector>
using namespace std;

// {
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
//}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	vector<size_t> a(n), b(m);
	cin >> a[0];
	for(size_t i=1; i<a.size(); ++i){
		cin >> a[i];
		a[i] += a[i-1];
	}
	cin >> b[0];
	for(size_t i=1; i<b.size(); ++i){
		cin >> b[i];
		b[i] += b[i-1];
	}
	view(a);
	view(b);


	/*
	for(auto& e : a) cin >> e;
	for(auto& e : b) cin >> e;
	auto read = [&k](vector<int>& v, size_t idx){
		if( k - v[idx] >= 0 ){
			k -= v[idx];
			return true;
		}
		return false;
	};
	size_t i = 0;
	size_t j = 0;
	int bookCount = 0;
	while(k>0 && (i!=a.size()-1 || j!=b.size()-1) ){
		if( i == a.size()-1 ){
			if( !read(b, j) ) break;
			bookCount++;
			j++;
		}
		if( j == b.size()-1 ){
			if( !read(a, i) ) break;
			bookCount++;
			i++;
		}
		if( a[i] < b[j] ){
			if( !read(a, i) ) break;
			bookCount++;
			i++;
		}else{
			if( !read(b, j) ) break;
			bookCount++;
			j++;
		}
	}
	cout << bookCount << endl;
	*/
	return 0;
}
