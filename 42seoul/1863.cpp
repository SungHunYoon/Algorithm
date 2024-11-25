#include <iostream>
#include <stack>

using namespace std;

int N, X, Y;
stack<int> stk;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		cin >> X >> Y;
		while (!stk.empty() && stk.top() > Y) {
			answer++;
			stk.pop();
		}
		if (!(!stk.empty() && stk.top() == Y) && Y > 0) stk.push(Y);
	}
	cout << answer + stk.size() << '\n';
	return 0;
}
