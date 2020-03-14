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

int factorial(int n){
	int ret = 1;
	while(n!=0){
		ret*=n;
		n--;
	}
	return ret;
}

void next(vector<int>& honest) {
	int bin = 1;
	int keta = 1;
	for(const auto& e : honest) {
		bin += e*keta;
		keta *= 2;
	}
	for(auto& e : honest) {
		e = bin % 2;
		bin /= 2;
	}
}

int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	vector<vector<int>> x(N);
	vector<vector<int>> y(N);
	for(int i=0; i<N; ++i) {
		cin >> A[i];
		x[i].resize(A[i]);
		y[i].resize(A[i]);
		for(int j=0; j<x[i].size(); ++j) {
			cin >> x[i][j] >> y[i][j];
//			x[i][j]--;
		}
	}
	vector<int> honest(N, 0);
	debug(honest);
	for(int i=0; i<factorial(N)+1; ++i){
		next(honest);
//		debug(honest);
	}
	return 0;
}
