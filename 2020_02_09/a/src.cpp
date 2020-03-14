#include <iostream>
#include <string>
using namespace std;

inline int num (const std::string& S, int idx){ return S.at(idx) - '0'; }
inline unsigned int bitMask(int i){ return (1 << i); }
inline bool isTrue(unsigned int bit, int i){ return bit & bitMask(i); }

int main(){
	string S, T;
	cin >> S >> T;
	int a, b;
	cin >> a >> b;
	string U;
	cin >> U;
	if(U == S){
		cout << (a-1) << " " << b << endl;
	}else{
		cout << a << " " << (b-1) << endl;
		}
	return 0;
}
