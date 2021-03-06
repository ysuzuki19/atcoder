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

int main(){
	int N;
	cin >> N;
	vector<unsigned long long> A(N);
	for(int i=0; i<N; ++i) { cin >> A[i]; }
	unsigned long long sums = 0;
	for(int i=0; i<N; ++i){
		for(int j=i+1; j<N; ++j){
//			sums += A[i]^A[j];
//			auto temp = A[i]^A[j];
//			cout << A[i] << " " << A[j] << " " << A[i]^A[j] << endl;
//			cout << A[i] << " " << A[j] << " " << temp << endl;
		}
		sums += A[i];
	}
	cout << sums % 1000000007 << endl;
	return 0;
}
