#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using si = pair<string, int>;

int convertCharToIdx(char c) {
	return (isdigit(c) ? c - '0' : c - 'A' + 10);
}

string calNumber(string a, string b) {
	const char T[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
					  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
					  'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
					  'U', 'V', 'W', 'X', 'Y', 'Z'};
	string ret;
	if (a.size() < b.size()) swap(a, b);
	int carry = 0;
	for (int i = a.size() - 1, j = b.size() - 1; i >= 0; i--, j--) {
		int dA = convertCharToIdx(a[i]);
		int dB = (j >= 0 ? convertCharToIdx(b[j]) : 0);
		int sum = dA + dB + carry;
		ret.push_back(T[sum % 36]);
		carry = sum / 36;
	}
	while (carry > 0) {
		ret.push_back(T[carry % 36]);
		carry /= 36;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

bool cmp(string &a, string &b) {
	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i]) {
				continue;
			} else if (isalpha(a[i]) && isdigit(b[i])) {
				return true;
			} else if (isdigit(a[i]) && isalpha(b[i])) {
				return false;
			} else {
				return a[i] > b[i];
			}
		}
	}
	return a.size() > b.size();
}

bool cmppair(si &a, si &b) {
	return cmp(a.first, b.first);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N;
	vector<string> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> K;
	string answer;
	for (int i = 0; i < N; i++) {
		answer = calNumber(answer, A[i]);
	}
	vector<si> candidate;
	for (int i = 0; i < 36; i++) {
		vector<string> B = A;
		string sum;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < B[j].size(); k++) {
				if (convertCharToIdx(B[j][k]) == i) {
					B[j][k] = 'Z';
				}
			}
			sum = calNumber(sum, B[j]);
		}
		if (!cmp(answer, sum) && sum != answer) candidate.push_back({sum, i});
	}
	sort(candidate.begin(), candidate.end(), cmppair);
	for (int i = 0; i < K && i < candidate.size(); i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < A[j].size(); k++) {
				if (convertCharToIdx(A[j][k]) == candidate[i].second) {
					A[j][k] = 'Z';
				}
			}
		}
	}
	answer.clear();
	for (int i = 0; i < N; i++) {
		answer = calNumber(answer, A[i]);
	}
	cout << answer << '\n';
	return 0;
}