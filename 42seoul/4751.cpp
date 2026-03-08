#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;

double outerProduct(vector<double> &X, vector<double> &Y, int a, int b, int c) {
	return ((X[a] * Y[b] + X[b] * Y[c] + X[c] * Y[a]) -
			(Y[a] * X[b] + Y[b] * X[c] + Y[c] * X[a])) / 2;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> N) {
		if (N == 0) {
			break;
		}
		vector<double> X, Y;
		for (int i = 0; i < N; i++) {
			double x, y;
			cin >> x >> y;
			X.push_back(x);
			Y.push_back(y);
		}
		double V, S = 0;
		cin >> V;
		for (int i = 1; i < N - 1; i++) {
			S += outerProduct(X, Y, 0, i, i + 1);
		}
		cout.precision(2);
		cout << "BAR LENGTH: " << fixed << fabs(V / S) << '\n';
	}

	return 0;
}