#include <iostream>
#include <string>
#include <vector>
#include <set>
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
template<typename T> void view(T e) noexcept { cout << e; }
template<typename T> void view(std::vector<T> v) noexcept { for(const auto& e : v) cout << e << " "; }
template<typename T> void view(std::vector<std::vector<T>> vv) noexcept { for(const auto& v : vv) view(v); }

bool isComplementary (vector<int> const& left_sum, vector<int> const& right_sum) {
	if ((left_sum['A']+right_sum['T']) % 4 != 0) return false;
	if ((left_sum['T']+right_sum['A']) % 4 != 0) return false;
	if ((left_sum['C']+right_sum['G']) % 4 != 0) return false;
	if ((left_sum['G']+right_sum['C']) % 4 != 0) return false;
	return true;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	std::string s;
	cin >> n >> s;

	vector<vector<int>> left_sum_lut  (n, vector<int>('U'-'A', 0));
	vector<vector<int>> right_sum_lut (n, vector<int>('U'-'A', 0));

	for (int i=1; i<s.length(); ++i) {
		left_sum_lut[j][s[i]-'A']++;
	}
	for (int i=0; i<s.length(); ++i) {
		for (int j=i; j<s.length(); ++j) {
			right_sum_lut[j][s[i]-'A']++;
		}
	}

	int ans = 0;

	int left = 0;
	while (left < s.length()) {
		int right = left + 1;
		while (right < s.length()) {
			cout << "left :  ";
			view(left_sum_lut[left]);
			cout << endl;
			cout << "right : ";
			view(right_sum_lut[right]);
			cout << endl;
			if (isComplementary(left_sum_lut[left], right_sum_lut[right])) {
				ans ++;
			}
			right += 2;
		}
		left++;
	}

	cout << ans << endl;
	return 0;
}
