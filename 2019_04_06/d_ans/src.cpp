#include <bits/stdc++.h>
using namespace std;


int main() {
	long X, Y, Z, K;
	vector<long>vec;

	cin >> X >> Y >> Z >> K;
	vector<long> A (X);
	vector<long> B (Y);
	vector<long> C (Z);

	for (int i=0; i<X; i++) cin >> A[i];
	sort(A.begin(), A.end(), greater<long>());

	for (int i=0; i<Y; i++) cin >> B[i];
	sort(B.begin(), B.end(), greater<long>());

	for (int i=0; i<Z; i++) cin >> C[i];
	sort(C.begin(), C.end(), greater<long>());

	for (int i=0; i<X && i+1<=K; i++)
		for (int j=0; j<Y && (i+1)*(j+1)<=K; j++)
			for (int k=0; k<Z && (i+1)*(j+1)*(k+1)<=K; k++)
				vec.push_back(A[i] + B[j] + C[k]);
	sort(vec.begin(), vec.end(), greater<long>());
	for (int i = 0; i < K; i++) cout << vec[i] << endl;
	return 0;
}

