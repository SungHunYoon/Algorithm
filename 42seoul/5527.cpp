#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int N;
int A[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vector<int> B;
	int len = 0;
	A[0] = -1;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (A[i] != A[i - 1]) {
			len++;
		} else {
			B.push_back(len);
			len = 1;
		}
	}
	B.push_back(len);
	if (B.size() <= 3) {
		cout << accumulate(B.begin(), B.end(), 0) << '\n';
	} else {
		int answer = 0;
		for (int i = 0; i < B.size() - 2; i++) {
			answer = max(answer, B[i] + B[i + 1] + B[i + 2]);
		}
		cout << answer << '\n';
	}

	return 0;
}