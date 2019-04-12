#include <bits/stdc++.h>
using namespace std;

int main(){
  // start process
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int counter = 0;
  int temp = a[0];
  while(temp%2 == 0){
    temp = temp >> 1;
    counter++;
  }
  if(counter == 0){
    cout << 0 << endl;
    return 0;
  }
  int division = 1 << counter;
  int flag = 1;
  while(flag == 1){
    for(int i=0; i<a.size(); i++){
      if(a[i]%division != 0){
        break;
      }
      if(i == a.size()-1){
        cout << counter << endl;
        return 0;
      }
    }
    division = division >> 1;
    counter--;
  }

  // end process
  return 0;
}
