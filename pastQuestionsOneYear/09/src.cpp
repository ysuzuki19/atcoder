#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	for(size_t i=0; i<s.length(); ++i){
		if( s.substr(i,5) == "maerd" ){
			i += 4;
			continue;
		}
		if( s.substr(i,7) == "remaerd" ){
			i += 6;
			continue;
		}
		if( s.substr(i,5) == "esare" ){
			i += 4;
			continue;
		}
		if( s.substr(i,6) == "resare" ){
			i += 5;
			continue;
		}
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}
