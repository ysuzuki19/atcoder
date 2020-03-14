#include <iostream>
using namespace std;

inline int num (const std::string& S, int idx){ return S.at(idx) - '0'; }
inline unsigned int bitMask(int i){ return (1 << i); }
inline bool isTrue(unsigned int bit, int i){ return bit & bitMask(i); }
inline bool isEven(int num) { return !num%2; }
inline bool isOdd(int num) { return num%2; }

int main(){
	unsigned long long h, w;
	cin >> h >> w;
	if(h==1 || w==1) {
		cout << 1 << endl;
		return 0;
	}
	if(h%2) {
		if(w%2){
			cout << h*w/2 + 1 << endl;
		}else{
			cout << h*w/2 << endl;
		}
	}else{
		if(w%2){
			cout << h*w/2 << endl;
		}else{
			cout << h*w/2 << endl;
		}
	}
	return 0;
}
