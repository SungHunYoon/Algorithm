#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int N;

bool checkArray(vector<int> &D) {
	for (int i = 1; i <= N; i++) {
		if (!D[i])
			return false;
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vector<int> A(N + 1);
	vector<int> B(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> B[i];
		A[i] = i;
	}
	vector<int> C(N + 1);
	vector<int> D(N + 1);
	int cnt = 1;
	while (!checkArray(D)) {
		for (int i = 1; i <= N; i++) {
			C[i] = A[B[i]];
			if (!D[i] && C[i] == i)
				D[i] = cnt;
		}
		A = C;
		cnt++;
	}
	int answer = 1;
	for (int i = 1; i <= N; i++)
		answer = lcm(answer, D[i]);
	cout << answer << '\n';
	return 0;
}