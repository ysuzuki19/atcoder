#include<bits/stdc++.h>
using namespace std;
int N;
vector<pair<int, int> > tree[101010];
vector<int> ans;

void dfs(int idx, int self, int c)
{
  ans[idx] = c;
  for(auto e: tree[idx])
    if(e.first != self)
      dfs(e.first, idx, c^e.second);
}

int main()
{
  cin >> N;
  for(int i=0; i<N-1; ++i)
  {
    int u, v, w;
    cin >> u >> v >> w;
    tree[u].emplace_back(v, w%2);
    tree[v].emplace_back(u, w%2);
  }
  ans.resize(N);
  dfs(1, 0, 0);
  for(int i=1; i<=N; ++i)
    cout << ans[i] << endl;
}
