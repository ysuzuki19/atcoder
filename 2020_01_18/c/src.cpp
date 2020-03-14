#include <bits/stdc++.h>
#define _ << ' ' <<
#define _squ(x)	((x) * (x))
#define debug(var)	do{std::cout << #var << " : "; view(var);}while(0)
#define line_debug(var)	do{std::cout << "l" << __LINE__ << " " << #var << " : "; view(var);}while(0)
#define _max(v)	*max_element(v.begin(), v.end())
#define _min(v)	*min_element(v.begin(), v.end())
#define _sort(var)	std::sort(var.begin(), var.end());
#define _rsort(var)	std::sort(var.begin(), var.end(), std::greater<>());
using namespace std;
using ll = long long;
int gcd(int m, int n){return !n ? m : gcd(n, m%n);}
template<typename T> using V = std::vector<T>;
template<typename T> using VV = std::vector<std::vector<T>>;
template<typename T> using VVV = std::vector<std::vector<std::vector<T>>>;
template<typename T> void view(const T e){ std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){ for(const auto& e : v) std::cout << e << " "; std::cout << std::endl; }
template<typename T> void view(const std::vector<std::vector<T>>& vv){ for(const auto& v : vv){ view(v); } }

struct robot{
	int x;
	int l;
};

bool cmp(robot a, robot b){
	return a.x < b.x;
}

void check_kasanari(vector<robot>& robots, vector<bool>& kasanari){
	for(auto i=0; i<kasanari.size(); ++i) if(kasanari[i]) kasanari[i] = false;
	if(robots.size()==1) return;
	for(auto i=0; i<robots.size(); ++i){
		if(i!=0)
			kasanari[i] = (robots[i-1].x+robots[i-1].l > robots[i].x-robots[i].l? true: false);
		if(i!=robots.size()-1 && !kasanari[i])
			kasanari[i] = (robots[i].x+robots[i].l > robots[i+1].x-robots[i+1].l? true: false);
	}
	return;
}

void reject_robots(vector<robot>& robots, vector<bool>& kasanari, int& N){
	for(auto i=0; i<robots.size(); ++i){
		if(kasanari[i]){
			if(kasanari[i+1]){
				robots[+1].x = 0; robots[i+1].l = 0; kasanari[i+1] = false;
				N--;
				i++;
			}
		}
	}
	for(auto i=robots.size()-1; i<robots.size(); --i){
		if(robots[i].x==0 && robots[i].l==0){
			robots.erase(robots.begin()+i);
			kasanari.erase(kasanari.begin()+i);
		}
	}
	return;
}

void view(const vector<robot>& robots){
	for(const auto& e : robots){
		cout << "[" << e.x << "," << e.l << "] ";
	}
	cout << endl;
}

int main(){
	int i, j;
	int N;
	cin >> N;
	vector<robot> robots(N);
	for(auto i=0; i<N; ++i) cin >> robots[i].x >> robots[i].l;
	sort(robots.begin(),robots.end(),cmp);
	vector<bool> kasanari(N, false);
	bool all_clear = false;
	while(!all_clear){
		check_kasanari(robots, kasanari);
		all_clear = true;
		for(const auto& e : kasanari) if(e){
			all_clear = false;
			break;
		}
		reject_robots(robots, kasanari, N);
		check_kasanari(robots, kasanari);
	}
	cout << N << endl;
	return 0;
}
