#include <bits/stdc++.h>
using namespace std;

class tree

void measure(const vector<int>& u, const vector<int>& v, const vector<int>& w, vector<int> distance, int beginPoint){

}

int main(){
  int i;
  int N;
  cin >> N;
  vector<int> u(N-1);
  vector<int> v(N-1);
  vector<int> w(N-1);
  for(i=0; i<N-1; i++){
    cin >> u[i] >> v[i] >> w[i];
  }
  vector<int> jd(N, 0);

  for(i=0; i<N-1; i++){
    jd[u[i]-1] ++;
    jd[v[i]-1] ++;
  }
  int beginPoint;
  for(i=0; i<N; i++)
    if(jd[i]==1)
      beginPoint = i;
  vector<int> distance (N, 0);
  measure(u, v, w, distance, beginPoint);

  cout << endl;
  for(const auto& e : jd)
    cout << e << " ";
  cout << endl;

//  vector<int> color(N);

  return 0;
}
