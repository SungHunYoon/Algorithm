#include <iostream>
#include <vector>

using namespace std;

int N, M;

void printArr(vector<vector<int>> &A) {
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[i].size(); j++) {
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
}

int dfs(vector<vector<int>> &A) {
	int ret = -1e9;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[i].size(); j++) {
			ret = max(ret, A[i][j]);
		}
	}

	for (int i = 0; i < A[0].size() - 1; i++) {
		vector<vector<int>> B(A.size(), vector<int>(max((int)A[0].size() - 1 - i, i + 1)));
		int boundary = i + 1;
		for (int j = 0; j < B[0].size(); j++) {
			for (int k = 0; k < B.size(); k++) {
				if (i - j >= 0) B[k][j] += A[k][i - j];
				if (boundary + j < A[0].size()) B[k][j] += A[k][boundary + j];
			}
		}
		ret = max(ret, dfs(B));
	}
	for (int i = 0; i < A.size() - 1; i++) {
		vector<vector<int>> B(max((int)A.size() - 1 - i, i + 1), vector<int>(A[0].size()));
		int boundary = i + 1;
		for (int j = 0; j < B.size(); j++) {
			for (int k = 0; k < B[0].size(); k++) {
				if (i - j >= 0) B[j][k] += A[i - j][k];
				if (boundary + j < A.size()) B[j][k] += A[boundary + j][k];
			}
		}
		ret = max(ret, dfs(B));
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	cout << dfs(A) << '\n';
	return 0;
}