#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int cntDigit(int n) {
	int ret = 0;
	while (n > 0) {
		n /= 10;
		ret++;
	}
	return ret;
}

vector<int> divideNum(int n) {
	vector<int> ret;
	while (n > 0) {
		ret.push_back(n % 10);
		n /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

bool dfs(vector<vector<int>> &A, vector<int> &B, vector<int> &V, int cnt) {
	if (cnt >= A.size() + 2) {
		set<int> idx;
		for (int i = 0; i < A.size(); i++) {
			int num = 0;
			for (int j = 0; j < A.size(); j++) {
				num = num * 10 + A[j][i];
			}
			auto it = find(B.begin(), B.end(), num);
			if (it == B.end()) return false;
			if (V[it - B.begin()]) return false;
			if (!idx.insert(it - B.begin()).second) return false;
		}
		return true;
	}
	for (int i = 0; i < B.size(); i++) {
		if (V[i]) continue;
		vector<int> C = divideNum(B[i]);
		if (cnt == 0) {
			V[i] = true;
			for (int j = 0; j < A.size(); j++) {
				A[j][j] = C[j];
			}
			if (dfs(A, B, V, cnt + 1)) {
				return true;
			}
			V[i] = false;
		} else if (cnt == 1) {
			V[i] = true;
			for (int j = 0; j < A.size(); j++) {
				A[j][A.size() - j - 1] = C[j];
			}
			if (dfs(A, B, V, cnt + 1)) {
				return true;
			}
			V[i] = false;
		} else {
			if (A[cnt - 2][cnt - 2] != C[cnt - 2] ||
				A[cnt - 2][A.size() - (cnt - 2) - 1] != C[A.size() - (cnt - 2) - 1]) continue;
			V[i] = true;
			copy(C.begin(), C.end(), A[cnt - 2].begin());
			if (dfs(A, B, V, cnt + 1)) {
				return true;
			}
			V[i] = false;
		}
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 51;
	for (int i = 2; i <= 10; i++) {
		vector<int> B;
		while (cntDigit(n) <= i) {
			B.push_back(n);
			n += 51;
		}
		vector<int> V(B.size());
		vector<vector<int>> A(i, vector<int>(i));
		if (dfs(A, B, V, 0)) {
			cout << i << '\n';
			for (int i = 0; i < A.size(); i++) {
				for (int j = 0; j < A[i].size(); j++) {
					cout << A[i][j] << ' ';
				}
				cout << '\n';
			}
			break;
		}
	}

	return 0;
}