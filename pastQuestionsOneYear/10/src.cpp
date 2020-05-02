#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, i;
	cin >> n;
	vector<int> t(n+1);
	vector<int> x(n+1);
	vector<int> y(n+1);
	t[0] = x[0] = y[0] = 0;
	for(int i=1; i<n+1; ++i) cin >> t[i] >> x[i] >> y[i];
	for(int i=1; i<n+1; ++i){
		int necessaryTime = abs(x[i]-x[i-1]) + abs(y[i]-y[i-1]);
		int diffTime = t[i] - t[i-1];
		bool isOdd = necessaryTime%2;
		if( diffTime < necessaryTime ){
			cout << "No" << endl;
			return 0;
		}
		if( diffTime%2 != necessaryTime%2 ){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
