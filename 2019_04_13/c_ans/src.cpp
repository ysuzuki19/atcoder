#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  char s=S[0];
	int bw = 0;
	int wb = 0;
  char w='0';
  char b='1';
  for(int i=0;i<S.size();i++){
		if(i%2==0){
      if(S[i]==b)bw++;
      else wb++;
		}else
      if(S[i]==w)bw++;
      else wb++;
  }
  cout << min(bw, wb) << endl;
  return 0;
}

