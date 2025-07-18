#include <iostream>
#include <stack>

using namespace std;

int G, N;
long A[102], B[101], D[102], T[102];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> G >> N;
	long S = 0;
	for (int i = 1; i <= N + 1; i++) {
		cin >> A[i];
		S += A[i];
		D[i] = 1e14;
	}
	for (int i = 1; i <= N; i++) {
		cin >> B[i];
	}
	if (S <= G) {
		cout << "0\n0\n";
		return 0;
	}
	S = 0;
	for (int i = 1; i <= N + 1; i++) {
		long P = S;
		S += A[i];
		for (int j = i - 1; P >= S - G && j >= 0; j--) {
			if (D[i] > D[j] + B[i]) {
				D[i] = D[j] + B[i];
				T[i] = j;
			}
			P -= A[j];
		}
	}
	cout << D[N + 1] << '\n';
	stack<int> stk;
	int idx = N + 1;
	while (T[idx]) {
		stk.push(T[idx]);
		idx = T[idx];
	}
	cout << stk.size() << '\n';
	while (!stk.empty()) {
		cout << stk.top() << ' ';
		stk.pop();
	}
	cout << '\n';

	return 0;
}