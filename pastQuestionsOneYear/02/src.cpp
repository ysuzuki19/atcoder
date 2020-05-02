#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin >> str;
	cout << count(str.begin(), str.end(), '1') << endl;
	return 0;
}
