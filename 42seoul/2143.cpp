#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M;
int A[1001], B[1001];
int pA[1001], pB[1001];

long calRange(vector<int> &arr, int val) {
	auto lf = lower_bound(arr.begin(), arr.end(), val);
	if (*lf == val) {
		auto uf = upper_bound(arr.begin(), arr.end(), val);
		return uf - lf;
	}
	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		pA[i] = pA[i - 1] + A[i];
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> B[i]; 
		pB[i] = pB[i - 1] + B[i];
	}
	vector<int> dA, dB;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < i; j++)
			dA.push_back(T - (pA[i] - pA[j]));
	for (int i = 1; i <= M; i++)
		for (int j = 0; j < i; j++)
			dB.push_back(pB[i] - pB[j]);
	sort(dB.begin(), dB.end());
	long answer = 0;
	for (int i = 0; i < dA.size(); i++)
		answer += calRange(dB, dA[i]);
	cout << answer << '\n';
	return 0;
}
