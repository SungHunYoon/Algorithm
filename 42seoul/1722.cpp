#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long N, K, S, P;
bool visit[21];
vector<int> A;
vector<int> B;

long factorial(long n) {
	if (n == 1)
		return 1;
	return n * factorial(n - 1);
}

int dfs(vector<int> &v) {
	if (v.size() >= N) {
		A = v;
		P++;
		if (K == 1 && P == S)
			return 1;
		else if (K == 2 && B[N - 1] == A[N - 1])
			return 1;
		return 0;
	}
	if (K == 1) {
		long f = factorial(N - v.size());
		if (S > P + f) {
			P += f;
			return 0;
		}
	} else {
		if (v.size() && v[v.size() - 1] != B[v.size() - 1]) {
			P += factorial(N - v.size());
			return 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			v.push_back(i);
			if (dfs(v))
				return 1;
			v.pop_back();
			visit[i] = false;
		}
	}
	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
	if (K == 1)
		cin >> S;
	else {
		for (int i = 0; i < N; i++) {
			cin >> S;
			B.push_back(S);
		}
	}
	vector<int> v;
	dfs(v);
	if (K == 1) {
		for (int i = 0; i < A.size(); i++)
			cout << A[i] << " ";
	} else
		cout << P;
	cout << '\n';
	return 0;
}