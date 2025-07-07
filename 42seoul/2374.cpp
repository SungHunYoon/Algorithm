#include <iostream>
#include <stack>

using namespace std;

int N;
int A[1001];
stack<int> stk;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	long answer = 0;
	for (int i = 1; i <= N; i++) {
		if (stk.empty() || stk.top() >= A[i]) {
			stk.push(A[i]);
		} else {
			int minV = 1e9, maxV = 0;
			while (!stk.empty() && stk.top() < A[i]) {
				minV = min(minV, stk.top());
				maxV = max(maxV, stk.top());
				stk.pop();
			}
			stk.push(A[i]);
			answer += maxV - minV;
			answer += A[i] - maxV;
		}
	}
	int minV = 1e9, maxV = 0;
	while (!stk.empty()) {
		minV = min(minV, stk.top());
		maxV = max(maxV, stk.top());
		stk.pop();
	}
	answer += maxV - minV;
	cout << answer << '\n';
	return 0;
}