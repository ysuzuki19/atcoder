#include <iostream>
#include <vector>
using namespace std;

#define debug(var)  do{ std::cout << #var << " : "; view(var); }while(0)
template<typename T> inline short sgn(T num) noexcept { return (num==0? 0 : (num>0? 1 : -1) ); }
template<typename T> void view(T e) noexcept { cout << e; }
template<typename T> void view(std::vector<T> v) noexcept { for(const auto& e : v) cout << e << " "; }
template<typename T> void view(std::vector<std::vector<T>> vv) noexcept { for(const auto& v : vv) view(v); }

class Header {
	public:
		Header(){}
		int m = 1;
		int i = 1;
		int r = 1;
		int bl = 1;
		int cl = 0;
		void input(){
			string buf; cin >> buf;
			cin >> m >> i >> r >> bl >> cl;
		}
		void output() const noexcept { cout<<m<<" "<<i<<" "<<r<<" "<<bl<<" "<<cl<<endl; }
};

class Machine {
	private:
		int m_ = 1;
		int rq_ = 1;
		int mn_ = 0;
		vector<int> md_;
	public:
		Machine(){}
		void input(int m){
			string buf; cin >> buf;
			cin >> m_ >> rq_ >> mn_;
			md_.resize(m);
			for(auto& e : md_) cin >> e;
		}
		void output() const noexcept {
			cout << m_ << " " << rq_ << " " << mn_ << " : ";
			view(md_);
			cout << endl;
		}
};

class Bom {
	public:
		int i = 0;
		int m = 0;
		int c = 1;
		int ec = 1;
		Bom(){}
		void input(){
			string buf; cin >> buf;
			cin >> i >> m >> c >> ec;
		}
		void output() const noexcept {
			cout << i << " " << m << " " << c << " " << ec << endl;
		}
};

class Combi {
	public:
		int m = 0;
		int iPre = 0;
		int iNext = 0;
		int t = 0;
		int cc = 0;
		Combi(){}
		void input(){
			string buf; cin >> buf;
			cin >> m >> iPre >> iNext >> t >> cc;
		}
		void output() const noexcept {
			cout << m << " " << iPre << " " << iNext << " " << t << " " << cc << endl;
		}
};

class Order {
	public:
		int r = 0;
		int i = 0;
		int e = 0;
		int d = 1;
		int q = 1;
		int qMin = 0;
		int pr = 1;
		int a = 1;
		Order(){}
		void input(){
			string buf; cin >> buf;
			cin >> r >> i >> e >> d >> q >> qMin >> pr >> a;
		}
		void output() const noexcept {
		cout << r << " " << i << " " << e << " " << d << " " << q << " " << qMin << " " << pr << " " << a << " " << endl;
		}
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	Header header;
	header.input();
	header.output();
	vector<Machine> machines(header.m);
	vector<Bom> boms(header.bl);
	vector<Combi> combis(header.cl);
	vector<Order> orders(header.r);

	for(auto& machine : machines) machine.input(header.m);
	for(auto& bom : boms)         bom.input();
	for(auto& combi : combis)     combi.input();
	for(auto& order : orders)     order.input();

	cout << "machine" << endl;
	for(const auto& machine : machines) machine.output();
	cout << "bom" << endl;
	for(const auto& bom : boms)         bom.output();
	cout << "combi" << endl;
	for(const auto& combi : combis)     combi.output();
	cout << "order" << endl;
	for(const auto& order : orders)     order.output();

	return 0;
}
