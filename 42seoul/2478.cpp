#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int mCnt = 0, mS, mE;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		int j = i, k = (i + 1) % N;
		while (cnt < N) {
			if (A[j] == 1 && A[k] == N) {
				cnt++;
			} else if (A[j] == A[k] + 1) {
				cnt++;
			} else {
				break;
			}
			j = (j + 1) % N;
			k = (k + 1) % N;
		}
		if (cnt > mCnt) {
			mCnt = cnt;
			mS = i;
			mE = k;
		}
	}
	vector<int> B(N);
	for (int i = 1; i <= N; i++) {
		B[i - 1] = i;
	}
	int rCnt = 0;
	vector<int> C;
	if (mCnt == N) {
		mS = 0;
		mE = N - 1;
		for (int i = mS; i < mE; i++) {
			C.push_back(A[i]);
		}
	} else {
		while (mS != mE){
			C.push_back(A[mS]);
			mS = (mS + 1) % N;
		}
	}
	reverse(C.begin(), C.end());
	int idx = -1;
	for (int i = 1; i < N; i++) {
		rCnt = i;
		for (int l = 0; l < N; l++) {
			bool flag = false;
			int k = (i + l) % N;
			for (int j = 0, m = l; j < C.size() && m < N; j++, m++) {
				if (C[j] != B[k])
					break;
				if (j + 1 == C.size()) {
					if ((i + l) % N == rCnt && B[k] == A[0])
						flag = false;
					else if (B[rCnt] == A[0])
						flag = false;
					else
						flag = true;
				}
				k = (k + 1) % N;
			}
			if (flag) {
				idx = (i + l) % N;
				break;
			}
		}
		if (idx != -1)
			break;
	}
	rotate(B.begin(), B.begin() + rCnt, B.end());
	cout << rCnt << '\n';
	int s = (idx - rCnt + 1 + N);
	int e = (idx - rCnt + C.size() + N);
	if (s > N) s -= N;
	if (e > N) e -= N;
	cout << s << " " << e << '\n';
	reverse(B.begin() + s - 1, B.begin() + e);
	for (int i = 1; i < N; i++) {
		int k = i;
		bool flag = true;
		for (int j = 0; j < A.size(); j++) {
			if (A[j] != B[k]) {
				flag = false;
				break;
			}
			k = (k + 1) % N;
		}
		if (flag) {
			rCnt = i;
			break;
		}
	}
	cout << rCnt << '\n';
	return 0;
}

// 1 2 3 4 5 6 7 8 9 10
// 2 3 4 5 6 7 8 9 10 1
// 2 3 4 7 6 5 8 9 10 1
