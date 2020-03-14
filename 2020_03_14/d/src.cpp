#include <iostream>
#include <cmath>
using namespace std;

inline int num (const std::string& S, int idx){ return S.at(idx) - '0'; }
inline unsigned int bitMask(int i){ return (1 << i); }
inline bool isTrue(unsigned int bit, int i){ return bit & bitMask(i); }
inline bool isEven(int num) { return !num%2; }
inline bool isOdd(int num) { return num%2; }

inline void increment(std::string& str, int i){ str[i] ++; }

int main(){
	int n;
	cin >> n;
	std::string str (n, 'a');
	int increment_keta = 1;
	for(int i=0; i<n; i++){
		cout << str << endl;
		if(str[n-increment_keta] == 'z'){
			str[n-increment_keta] = 'a';
			increment_keta ++;
		}
		increment(str, n-increment_keta);
	}
	return 0;
}
