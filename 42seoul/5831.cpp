#include <iostream>
#include <vector>

using namespace std;

long N, B;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> B;
	int state = 0;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		state |= (n << (N - i - 1));
	}
	vector<int> A;
	vector<int> V(1 << N, -1);
	for (long j = 0; j < B; j++) {
		if (V[state] != -1) {
			long idx = V[state] + ((B - V[state]) % (A.size() - V[state]));
			state = A[idx];
			break;
		}
		V[state] = A.size();
		A.push_back(state);
		state |= (state & 0x01) << N;
		int nState = 0;
		for (int i = N - 1; i >= 0; i--) {
			if (state & (1 << (i + 1))) {
				if (!(state & (1 << i))) {
					nState |= 1 << i;
				} else {
					nState &= ~(1 << i);
				}
			} else {
				nState |= state & (1 << i);
			}
		}
		state = nState;
		
	}
	for (int i = N - 1; i >= 0; i--) {
		cout << ((state & (1 << i)) ? '1' : '0') << '\n';
	}
	return 0;
}