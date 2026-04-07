#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <complex>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;
using cpx = complex<double>;

#define MOD 1000000007

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

vector<long> convolution(vector<long> &a) {
	vector<long> b = a;
	vector<long> ret(a.size() + b.size() - 1);
	int n = 1;
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
	for (int i = 0; i < n; i++) {
		nA[i] *= nB[i];
	}
	fft(nA, cpx(1, 0) / w);
	for (int i = 0; i < ret.size(); i++) {
		ret[i] = ((long)round(nA[i].real() / n) % MOD);
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, R, Q;
	cin >> N >> R;
	vector<vector<int>> V(N + 1, vector<int>());
	for (int i = 1; i <= N - 1; i++) {
		int u, v;
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	vector<int> D(N + 1, 1e9);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({D[R] = 0, R});
	while (!pq.empty()) {
		auto [d, n] = pq.top(); pq.pop();
		if (d > D[n]) continue;
		for (auto nN : V[n]) {
			if (d + 1 >= D[nN]) continue;
			pq.push({D[nN] = d + 1, nN});
		}
	}
	vector<long> A(300001);
	for (int i = 1; i <= N; i++) {
		if (D[i] == 0 || D[i] == 1e9 || V[i].size() != 1) continue;
		A[D[i]]++;
	}
	vector<long> ret = convolution(A);
	vector<long> prefix(ret.size() + 1);
	for (int i = 0; i < ret.size(); i++) {
		prefix[i + 1] = (prefix[i] + ret[i]) % MOD;
	}
	cin >> Q;
	while (Q--) {
		int w, v;
		cin >> w >> v;
		cout << (prefix[v + 1] - prefix[w] + MOD) % MOD << '\n';
	}

	return 0;
}