#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

int N;
int A[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	sort(A, A + N);
	vector<int> B;
	for (int i = 0; i < N - 1; i++)
		B.push_back(A[i + 1] - A[i]);
	int g = B[0];
	for (int i = 1; i < B.size(); i++)
		g = gcd(max(B[i], g), min(B[i], g));
	for (int i = 2; i <= sqrt(g); i++)
		if (g % i == 0)
			cout << i << ' ';
	cout << '\n';
	return 0;
}
