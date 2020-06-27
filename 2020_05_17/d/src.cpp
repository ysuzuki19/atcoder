#include <iostream>
#include <vector>
#include <list>
#include <queue>
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
	int n, m;
	cin >> n >> m;
	vector<list<int>> connects(n+1);
	for(int i=0; i<m; ++i){
		int a, b;
		cin >> a >> b;
		connects[a].push_back(b);
		connects[b].push_back(a);
	}
	vector<int> distances(n+1, INT_MAX);
	queue<int> onSearching;
	onSearching.push(1);
	int distance = 0;
	while( !onSearching.empty() ){
		int counter = onSearching.size();
		while ( counter ){
			int buf = onSearching.front();
			cout << "buf : " << buf << endl;
			cout << "distance : " << distance << endl;
			distances[buf] = distance;
			for(const auto& next : connects[buf]){
				if( distances[next] == INT_MAX ) onSearching.push(next);
			}
			onSearching.pop();
			counter--;
		}
		distance++;
	}
	if( !n ){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for(int i=2; i<distances.size(); ++i){
		cout << distances[i] << endl;
	}
	return 0;
}
