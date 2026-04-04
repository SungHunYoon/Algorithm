#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <algorithm>

using namespace std;

void fft(vector<complex<double>> &v, complex<double> w) {
	int n = v.size();
	if (n == 1) return;
	vector<complex<double>> even(n / 2), odd(n / 2);
	for (int i = 0; i < n / 2; i++) {
		even[i] = v[i * 2];
		odd[i] = v[i * 2 + 1];
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

vector<int> convolution(vector<int> &a, vector<int> &b) {
	int n = 1;
	vector<int> ret(a.size() + b.size() - 1);
	while (n < a.size() + b.size()) n *= 2;
	a.resize(n);
	b.resize(n);
	vector<complex<double>> nA(n), nB(n);
	for (int i = 0; i < a.size(); i++) {
		nA[i] = complex<double>(a[i], 0);
	}
	for (int i = 0; i < b.size(); i++) {
		nB[i] = complex<double>(b[i], 0);
	}
	const double PI = acos(-1);
	complex<double> w(cos(2 * PI / n), sin(2 * PI / n));
	fft(nA, w);
	fft(nB, w);
	vector<complex<double>> ifft(n);
	for (int i = 0; i < n; i++) {
		ifft[i] = nA[i] * nB[i];
	}
	fft(ifft, complex<double>(1, 0) / w);
	for (int i = 0; i < ret.size(); i++) {
		ret[i] = round(ifft[i].real() / n);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	for (int i = 0; i < N; i++) {
		A.push_back(A[i]);
	}
	reverse(B.begin(), B.end());
	vector<int> ret = convolution(A, B);
	int answer = 0;
	for (int i = N - 1; i < N + N; i++) {
		answer = max(answer, ret[i]);
	}
	cout << answer << '\n';
	return 0;
}