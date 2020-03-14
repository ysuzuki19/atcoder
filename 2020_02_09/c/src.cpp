#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

inline int num (const std::string& S, int idx){ return S.at(idx) - '0'; }
inline unsigned int bitMask(int i){ return (1 << i); }
inline bool isTrue(unsigned int bit, int i){ return bit & bitMask(i); }

int main(){
	int N;
	cin >> N;
	vector<int> v(N);
	for(auto& e : v) cin >> e;
	sort(v.begin(), v.end());
	if(v[0]==v[1]){
		cout << "NO" << endl;
		return 0;
	}
	for(std::size_t i=1; i<v.size(); ++i){
		if(v[i]==v[i-1]){
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
