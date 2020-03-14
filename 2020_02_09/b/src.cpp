#include <iostream>
#include <string>
using namespace std;

inline int num (const std::string& S, int idx){ return S.at(idx) - '0'; }
inline unsigned int bitMask(int i){ return (1 << i); }
inline bool isTrue(unsigned int bit, int i){ return bit & bitMask(i); }

int main(){
	string S;
	cin >> S;
	for(std::size_t i=0; i<S.length(); ++i){
		cout << "x";
	}
	cout << endl;
	return 0;
}
