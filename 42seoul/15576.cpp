#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>

using namespace std;

#define PI 3.141592

void fft(vector<complex<double>> &v, complex<double> w) {
	int n = v.size();
	if (n == 1) return;
	vector<complex<double>> even(n / 2), odd(n / 2);
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) even[i / 2] = v[i];
		else odd[i / 2] = v[i];
	}
	fft(even, w * w);
	fft(odd, w * w);
	complex<double> z(1, 0);
	for (int i = 0; i < n / 2; i++) {
		v[i] = even[i] + z * odd[i];
		v[i + n / 2] = even[i] - z * odd[i];
		z *= w;
	}
}

vector<long> multifly(vector<int> &a, vector<int> &b) {
	vector<long> ret(a.size() + b.size() - 1);
	int n = 1;
	while (n <= a.size() + b.size()) n *= 2;
	a.resize(n);
	b.resize(n);
	vector<complex<double>> nA(n), nB(n);
	for (int i = 0; i < n; i++) {
		nA[i] = complex<double>(a[i], 0);
	}
	for (int i = 0; i < n; i++) {
		nB[i] = complex<double>(b[i], 0);
	}
	complex<double> w(cos(2 * PI / n), sin(2 * PI / n));
	fft(nA, w);
	fft(nB, w);
	vector<complex<double>> revFFT(n);
	for (int i = 0; i < revFFT.size(); i++) {
		revFFT[i] = nA[i] * nB[i];
	}
	fft(revFFT, complex<double>(1, 0) / w);
	for (int i = 0; i < revFFT.size(); i++) {
		revFFT[i] /= complex<double>(n, 0);
	}
	for (int i = 0; i < ret.size(); i++) {
		ret[i] = round(revFFT[i].real());
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string A, B;
	cin >> A >> B;
	vector<int> aV(A.size()), bV(B.size());
	for (int i = 0; i < A.size(); i++) {
		aV[i] = A[i] - '0';
	}
	for (int i = 0; i < B.size(); i++) {
		bV[i] = B[i] - '0';
	}
	vector<long> ret = multifly(aV, bV);
	reverse(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); i++) {
		long val = ret[i] / 10;
		int d = i + 1;
		while (val > 0) {
			if (d >= ret.size())
				ret.push_back(val % 10);
			else
				ret[d] += val % 10;
			val /= 10;
			d++;
		}
		ret[i] %= 10;
	}
	reverse(ret.begin(), ret.end());
	for (auto r : ret) {
		cout << r;
	}
	cout << '\n';
	return 0;
}