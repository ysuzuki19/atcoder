#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, x;
	cin >> a >> b >> c >> x;
	int pattern = 0;
	for(int i=0; i<=a; ++i){
		int money = 500*i;
		if(money > x) break;
		for(int j=0; j<=b; ++j){
			if(money > x) break;
			if(x-money <= 50*c) pattern++;
			money += 100;
		}
	}
	cout << pattern << endl;
	return 0;
}
