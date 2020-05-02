#include <bits/stdc++.h>
using namespace std;

int digitSum(int num){
	int sum = 0;
	while( num != 0){
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	int sum = 0;
	for(int i=0; i<=n; ++i){
		if( a<=digitSum(i) && digitSum(i)<=b ) sum += i;
	}
	cout << sum << endl;
	return 0;
}
