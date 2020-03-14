#include <iostream>
#include <string>
using namespace std;

inline int num (const std::string& S, int idx){ return S.at(idx) - '0'; }
inline unsigned int bitMask(int i){ return (1 << i); }
inline bool isTrue(unsigned int bit, int i){ return bit & bitMask(i); }

int main(){
	int i;
	cin >> i;
	cout << i/2 + i%2 << endl;
	return 0;
}
