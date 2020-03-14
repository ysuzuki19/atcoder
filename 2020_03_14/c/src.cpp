#include <iostream>
#include <cmath>
using namespace std;

inline int num (const std::string& S, int idx){ return S.at(idx) - '0'; }
inline unsigned int bitMask(int i){ return (1 << i); }
inline bool isTrue(unsigned int bit, int i){ return bit & bitMask(i); }
inline bool isEven(int num) { return !num%2; }
inline bool isOdd(int num) { return num%2; }

int main(){
	int a, b, c;
	cin >> a >> b >> c;
	if(a==c || b==c){
		cout << "No" << endl;
		return 0;
	}
	if( a + b >= c ){
		cout << "No" << endl;
		return 0;
	}
	long double ld_a, ld_b, ld_c;
	ld_a = a;
	ld_b = b;
	ld_c = c;
	if( 2.0*sqrt(ld_a*ld_b) < ld_c - ld_a - ld_b ){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}
