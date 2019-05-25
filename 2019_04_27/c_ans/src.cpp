#include <bits/stdc++.h>
#define _ << ' ' <<
using namespace std;
using vi = vector<int>;
using ll = long long;
void view(const vector<int>& v){for(const auto& e : v)cout << e << " ";cout << endl;}
int gcd(int m, int n){return !n ? m : gcd(n, m%n);}


int main(){
	int i, j;
	ll n;
	cin >> n;
	vi a(n+2);
// 端に0を埋めることが後で生きてくる
//TODO	a[0] = a[a.size()] = 0; was failed.
	a[0] = a[a.size()-1] = 0;
	for(i=1; i<=n; i++) cin >> a[i];
	vi l = a;	vi r = a;
	for (int i = 1; i <= n; ++i) l[i] = gcd(l[i - 1], l[i]);
	for (int i = n; i >= 1; --i) r[i] = gcd(r[i + 1], r[i]);

	int maxCommonDivisor = 0;
// 端にある0のおかげで要素外参照を防ぐ
	for(i=1; i<=n; i++)
		maxCommonDivisor = max(maxCommonDivisor, gcd(l[i-1], r[i+1]));
	cout << maxCommonDivisor << endl;
	return 0;
}
