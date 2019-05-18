#include <bits/stdc++.h>
using namespace std;

int main(){
  long n;
  cin >> n;
  vector<long> capasity(5);
  cin >> capasity[0];
  long minTemp = capasity[0];
  for(int i=1; i<capasity.size(); i++){
    cin >> capasity[i];
    minTemp = min(minTemp, capasity[i]);
  }
  cout << (n-1)/minTemp + 5 << endl;
  return 0;
}
