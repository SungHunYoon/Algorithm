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

vector<int> multiply(vector<int> &A, vector<int> &B) {
	int n = 1;
	vector<int> ret(A.size() + B.size() - 1);
	while (n < A.size() + B.size()) n *= 2;
	A.resize(n);
	B.resize(n);
	vector<complex<double>> nA(n), nB(n);
	for (int i = 0; i < A.size(); i++) {
		nA[i] = complex<double>(A[i], 0);
	}
	for (int i = 0; i < B.size(); i++) {
		nB[i] = complex<double>(B[i], 0);
	}
	const double PI = acos(-1);
	complex<double> w(cos(2 * PI / n), sin(2 * PI / n));
	fft(nA, w);
	fft(nB, w);
	vector<complex<double>> R(n);
	for (int i = 0; i < n; i++) {
		R[i] = nA[i] * nB[i];
	}
	fft(R, complex<double>(1, 0) / w);
	for (int i = 0; i < ret.size(); i++) {
		ret[i] = round(R[i].real() / n);
		if (ret[i] > 0) ret[i] = 1;
	}
	return ret;
}

void fast_pow(vector<int> &A, int k) {
	if (k == 1) {
		return;
	}
	vector<int> B = A;
	fast_pow(A, k / 2);
	vector<int> C = A;
	A = multiply(A, C);
	if (k % 2) A = multiply(A, B);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;
	vector<int> A(1001);
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		A[n] += 1;
	}
	fast_pow(A, K);
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == 0) continue;
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}