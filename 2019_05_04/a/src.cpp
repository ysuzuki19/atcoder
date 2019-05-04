#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  int i, j;
  cin >> H >> W;
  vector<vector<int>> shp;
  vector<vector<int>> dot;
  char temp;
  for(i=0; i<H; i++){
    for(j=0; j<W; j++){
      cin >> temp;
      vector<int> idx = {i, j};
      if(temp == '#'){
        shp.push_back(idx);
      }else{
        dot.push_back(idx);
      }
    }
  }
  int minDst;
  int Dst;
  int maxDst = 0;
  for(size_t i=0; i<dot.size(); i++){
    minDst = abs(dot[i][0]-shp[0][0]) + abs(dot[i][1]-shp[0][1]);
    Dst = minDst;
    for(size_t j=1; j<shp.size(); j++){
      Dst = abs(dot[i][0]-shp[j][0]) + abs(dot[i][1]-shp[j][1]);
      if(Dst < minDst){
        minDst = Dst;
      }
    }
    if(maxDst < minDst){
      maxDst = minDst;
    }
  }
  cout << maxDst << endl;
  return 0;
}
