#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int N;

void calBeauty(vector<int> &A, long &answerNum, long &answerDen) {
	vector<int> S;
	for (int i = 0; i < N; i++) {
		while (!S.empty() && A[S.back()] <= A[i]) {
			S.pop_back();
		}
		if (!S.empty()) {
			int idx = S.back();
			long den = A[idx] - A[idx + 1];
			long num = (i - idx) * den - (A[idx] - A[i]);
			if (answerNum * den < num * answerDen) {
				answerNum = num;
				answerDen = den;
			}
		}
		S.push_back(i);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	long answerNum = 0, answerDen = 1;
	
	calBeauty(A, answerNum, answerDen);
	reverse(A.begin(), A.end());
	calBeauty(A, answerNum, answerDen);

	long g = gcd(answerNum, answerDen);
	answerNum /= g;
	answerDen /= g;
	if (answerDen == 1) {
		cout << answerNum << '\n';
	} else {
		cout << answerNum << "/" << answerDen << '\n';
	}

	return 0;
}