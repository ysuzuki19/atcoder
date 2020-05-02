#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto& e : a) cin >> e;
	int counter = -1;
	bool isDividable = true;
	while(isDividable){
		for(auto& e : a){
			if( e == 0 ) isDividable = false;
			if( e%2 == 0 ) e /= 2;
			else isDividable = false;
		}
		counter++;
	}
	cout << counter << endl;
	return 0;
}
