#include <bits/stdc++.h>
using namespace std;
#define _ << ' ' <<
using ll = long long;
using vi = vector<int>;
void view(const vector<int>& v){for(const auto& e : v)cout << e << " ";cout << endl;}

int main(){
	int i;
	int n, k;
	string s;
	cin >> n >> k >> s;
	s += 'x';
	vector<int> organ;
	char past = s[0];
	int count = 0;
	for(i=0; i<s.length(); ++i){
		if(past != s[i]) organ.push_back(count), count = 0;
		count ++;
		past = s[i];
	}
	for (int i=1; i<organ.size(); ++i)
		organ[i] += organ[i - 1];
	int humanState = (s[0] == '1');
	int maxHuman = 0;
	for(i=0; i<organ.size(); ++i){
    int humans;
    if(organ.size()<i+2*k+(humanState+i)%2){
      humans = organ[organ.size()-1] - (i? organ[i-1] : 0);
    }else{
      humans = organ[i+2*k-1+(humanState+i)%2] - (i? organ[i-1] : 0);
    }
		maxHuman = max(maxHuman, humans);
	}
	cout << maxHuman << endl;
	return 0;
}
