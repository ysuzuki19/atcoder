#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline int num (const std::string& S, int idx){ return S.at(idx) - '0'; }
inline unsigned int bitMask(int i){ return (1 << i); }
inline bool isTrue(unsigned int bit, int i){ return bit & bitMask(i); }

int main(){
	int N, M;
	cin >> N >> M;
	if(N==0){
		cout << -1 << endl;
		return 0;
	}
	if(M==0){
		if(N==1){
			cout << 0 << endl;
			return 0;
		}
		cout << 1;
		for(int i=0; i<N-1; ++i){
			cout << 0;
		}
		cout << endl;
		return 0;
	}
	vector<int> s(N);
	vector<int> c(N);
	for(int i=0; i<N; ++i) cin >> s[i] >> c[i];
	for(int i=0; i<M; ++i){
		for(int j=0; j<M; ++j){
			if(s[i]==s[j] && c[i]!=c[j]){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	vector<int> num_loc(N, -1);
	for(int i=0; i<N; ++i) num_loc[s[i]-1] = c[i];
	if(num_loc[0] == 0){
		if(N==1){
			cout << 0 << endl;
			return 0;
		}
		cout << -1 << endl;
		return 0;
	}
	if(num_loc[0] == -1){
		if(N==1){
			cout << 0 << endl;
			return 0;
		}
		num_loc[0] = 1;
	}
	for(const auto& e : num_loc) cout << (e==-1? 0 : e);
	cout << endl;
	return 0;
}
