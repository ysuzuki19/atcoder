#include <bits/stdc++.h>
using namespace std;

int check(vector<int>& v){
  int maxTemp = 0;
  int temp;
  for(int i=0; i<v.size(); i++){
    temp = 0;
    for(int j=i; j<v.size(); j++){
      if(v[j]==1){
        temp++;
      }else{
        break;
      }
    }
    if(temp>maxTemp){
      maxTemp = temp;
    }
  }
  return maxTemp;
}

void revVar(vector<int>& v, int l, int r){
  for(int i=l; i<r; i++){
    if(v[i]==0){
      v[i] = 1;
    }else{
      v[i] = 0;
    }
  }
}

vector<int> summaryContinuity(vector<int>& v){
  vector<int> summ;
  for(int i=0; i<v.size();){
    int temp = v[i];
    int cont = 1;
    for(int j=i+1; j<v.size(); j++){
      if(v[j]==temp){
        cont++;
      }else{
        break;
      }
    }
    if(temp==1){
      summ.push_back(cont);
//    }else{
//      summ.push_back(0);
    }
    i += cont;
  }
  return summ;
}

int maxContinuity(vector<int>& v, int k){
  int maxTemp = 0;
  for(int i=0; i<v.size()-k; i++){
    int sumTemp = v[i];
    for(int j=i; j<i+k; j++){
      cout << sumTemp << " " ;
      sumTemp += v[j];
    }
    cout << endl;
    if(sumTemp > maxTemp){
      maxTemp = sumTemp;
    }
  }
  return maxTemp;
}

int main(){
  // start process
  int i,j;
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> v(n);
  for(i=0; i<n; i++){
    if(s[i]=='0'){
      v[i] = 0;
    }else{
      v[i] = 1;
    }
  }
  vector<int> summary;
  summary = summaryContinuity(v);
  for(int i=0; i<summary.size(); i++){
    cout << summary[i] << " ";
  }cout << endl;
  cout << maxContinuity(summary, k) << endl;
//  cout << check(v) << endl;
  // end process
  return 0;
}
