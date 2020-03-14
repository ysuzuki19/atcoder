#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline int num (const std::string& S, int idx){ return S.at(idx) - '0'; }
inline unsigned int bitMask(int i){ return (1 << i); }
inline bool isTrue(unsigned int bit, int i){ return bit & bitMask(i); }

void set(int hit, int A[9], bool OK[9]){
	for(int i=0; i<9; ++i){
		if(hit == A[i]){
			OK[i] = true;
		}
	}
}

bool bingo(bool OK[9]){
	if(OK[0] && OK[1] && OK[2]) return true;
	if(OK[3] && OK[4] && OK[5]) return true;
	if(OK[6] && OK[7] && OK[8]) return true;
	if(OK[0] && OK[3] && OK[6]) return true;
	if(OK[1] && OK[4] && OK[7]) return true;
	if(OK[2] && OK[5] && OK[8]) return true;
	if(OK[0] && OK[4] && OK[8]) return true;
	if(OK[2] && OK[4] && OK[6]) return true;
	return false;
}

int main(){
	int A[9];
	cin >> A[0] >> A[1] >> A[2] >> A[3] >> A[4] >> A[5] >> A[6] >> A[7] >> A[8];
	int N;
	cin >> N;
	bool OK[9] = {false};
	for(int i=0; i<N; ++i){
		int hit;
		cin >> hit;
		set(hit, A, OK);
		if(bingo(OK)){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
