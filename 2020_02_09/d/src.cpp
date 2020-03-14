#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

inline int num (const std::string& S, int idx){ return S.at(idx) - '0'; }
inline unsigned int bitMask(int i){ return (1 << i); }
inline bool isTrue(unsigned int bit, int i){ return bit & bitMask(i); }
void view(const std::vector<int>& v){ for(const auto& e:v) cout << e << " "; cout << endl; }
void view(const std::vector<double>& v){ for(const auto& e:v) cout << e << " "; cout << endl; }

int main(){
	int N, K;
	cin >> N >> K;
	vector<double> v(N);
	for(auto& e : v){
		cin >> e;
		e = (1.0+e)*0.5;
	}
	//view(v);
	vector<double> expect(N-K+1, 0.0);
	//for(int i=0; i<N-K+1; ++i){
		//for(int j=0; j<K; ++j){
			//expect.at(i) += v.at(i+j);
		//}
	//}
	for(int i=0; i<K; ++i) expect.at(0) += v.at(i);
	for(int i=1; i<expect.size(); ++i){
		expect.at(i) = (expect.at(i-1)+v.at(i+K-1)-v.at(i-1));
	}
	//view(v);
	//view(expect);
	double maximum = 0.0;
	//view(expect);
	for(const auto& e : expect) maximum = max(maximum, e);
	cout << fixed << maximum << endl;
	return 0;
}
