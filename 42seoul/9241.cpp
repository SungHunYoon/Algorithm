#include <iostream>

using namespace std;

string A, B;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> A >> B;
	int preCnt = 0, surCnt = 0;
	for (int i = 0; i < min(A.size(), B.size()); i++) {
		if (A[i] != B[i]) break;
		preCnt++;
	}
	for (int aIdx = A.size() - 1, bIdx = B.size() - 1; aIdx >= 0 && bIdx >= 0; aIdx--, bIdx--) {
		if (A[aIdx] != B[bIdx]) break;
		surCnt++;
	}
	if (preCnt + surCnt >= B.size()) {
		if (A.size() > B.size()) {
			cout << "0\n";
		} else {
			cout << max(A.size(), B.size()) - min(A.size(), B.size()) << '\n';
		}
	} else {
		cout << B.size() - (preCnt + surCnt) << '\n';
	}
	return 0;
}