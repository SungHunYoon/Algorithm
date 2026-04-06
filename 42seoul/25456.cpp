#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <algorithm>

using namespace std;
using cpx = complex<double>;

void fft(vector<cpx> &v, cpx w) {
	int n = v.size();
	if (n == 1) return;
	vector<cpx> even(n / 2), odd(n / 2);
	for (int i = 0; i < n / 2; i++) {
		even[i] = v[i * 2];
		odd[i] = v[i * 2 + 1];
	}
	fft(even, w * w);
	fft(odd, w * w);
	cpx z(1, 0);
	for (int i = 0; i < n / 2; i++) {
		v[i] = even[i] + z * odd[i];
		v[i + n / 2] = even[i] - z * odd[i];
		z *= w;
	}
}

vector<int> convolution(vector<int> &a, vector<int> &b) {
	int n = 1;
	vector<int> ret(a.size() + b.size() - 1);
	while (n < a.size() + b.size()) n *= 2;
	a.resize(n);
	b.resize(n);
	vector<cpx> nA(n), nB(n);
	for (int i = 0; i < n; i++) {
		nA[i] = cpx(a[i], 0);
		nB[i] = cpx(b[i], 0);
	}
	const double PI = acos(-1);
	cpx w(cos(2 * PI / n), sin(2 * PI / n));
	fft(nA, w);
	fft(nB, w);
	vector<cpx> R(n);
	for (int i = 0; i < n; i++) {
		R[i] = nA[i] * nB[i];
	}
	fft(R, cpx(1, 0) / w);
	for (int i = 0; i < ret.size(); i++) {
		ret[i] = round(R[i].real() / n);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string A, B;
	cin >> A >> B;
	vector<int> v1(A.size()), v2(B.size());
	for (int i = 0; i < v1.size(); i++) {
		if (A[i] == '1') v1[i] = 1;
		if (B[i] == '1') v2[i] = 1;
	}
	vector<int> ret = convolution(v1, v2);
	cout << *max_element(ret.begin(), ret.end()) << '\n';

	return 0;
}