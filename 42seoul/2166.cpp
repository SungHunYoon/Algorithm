#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = pair<long, long>;

int N;
ll A[10001];

long outerProduct(ll c1, ll c2, ll c3) {
	return ((c2.first - c1.first) * (c3.second - c1.second) -
	(c3.first - c1.first) * (c2.second - c1.second));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i].first >> A[i].second;
	double answer = 0;
	for (int i = 1; i < N - 1; i++)
		answer += outerProduct(A[0], A[i], A[i + 1]);
	cout.precision(1);
	cout << fixed << round(abs(answer / 2) * 10) / 10 << '\n';
	return 0;
}