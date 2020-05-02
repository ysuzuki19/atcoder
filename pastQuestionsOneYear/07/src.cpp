#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> d(n);
	for(auto& e : d) cin >> e;
	sort(d.begin(), d.end());
	int counter = 1;
	for(int i=0; i<n-1; ++i){
		if(d[i]!=d[i+1]) counter++;
	}
	cout << counter << endl;
	return 0;
}
