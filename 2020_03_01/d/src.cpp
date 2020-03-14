#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

inline int num (const std::string& S, int idx){ return S.at(idx) - '0'; }
inline unsigned int bitMask(int i){ return (1 << i); }
inline bool isTrue(unsigned int bit, int i){ return bit & bitMask(i); }

class UnionFind {
	private:
		vector<int> parent_;
		vector<int> sizes_;
	public:
		UnionFind(int N) : parent_(N), sizes_(N, 1) {
			for(int i=0; i<N; ++i) parent_[i] = i;
		}
		int root(int x) {
			if(parent_[x] == x) return x;
			return parent_[x] = root(parent_[x]);
		}
		void unite(int x, int y) {
			x = root(x);
			y = root(y);
			if( x == y ) return;
			if(sizes_[x] < sizes_[y]){
				sizes_[y] += sizes_[x];
				parent_[x] = y;
			}else{
				sizes_[x] += sizes_[y];
				parent_[y] = x;
			}
		}
		bool same(int x, int y) {
			return root(x) == root(y);
		}
		int members(int x) {
			return sizes_[root(x)];
		}
		void view_sizes() {
			for(const auto& e : sizes_){
				cout << e << " ";
			}
			cout << endl;
		}
};

bool isExist (std::list<int>& lst, int val){
	for(const auto& e : lst){
		if(e == val) return true;
	}
	return false;
}

int main(){
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> a(M), b(M), c(K), d(K);
	for(int i=0; i<M; ++i){ cin >> a[i] >> b[i]; }
	for(int i=0; i<K; ++i){ cin >> c[i] >> d[i]; }
	UnionFind uftree_friends(N);
	for(int i=0; i<a.size(); ++i){ uftree_friends.unite(a[i]-1, b[i]-1); }
	vector<list<int>> direct_friend(N, list<int>());
	for(int i=0; i<a.size(); ++i){
		direct_friend[a[i]-1].push_back(b[i]-1);
		direct_friend[b[i]-1].push_back(a[i]-1);
	}
	vector<list<int>> direct_block(N, list<int>());
	for(int i=0; i<c.size(); ++i){
		direct_block[c[i]-1].push_back(d[i]-1);
		direct_block[d[i]-1].push_back(c[i]-1);
	}

	for(int i=0; i<N; ++i){
		//int potencial = 0;
		int potencial = uftree_friends.members(i);
		for(int j=0; j<N; ++j){
			if( uftree_friends.same(i,j) ){
				if( isExist(direct_friend[i], j) || isExist(direct_block[i], j) ){
					potencial--;
				}
			}
		}
		cout << potencial-1 << " ";
	}
	cout << endl;
	//uftree_friends.view_sizes();

	return 0;
}
