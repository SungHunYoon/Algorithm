#include <iostream>

using namespace std;

int N;
int A[100001];
bool V[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	long answer = 0;
	for (int i = 0, j = 0; i < N; i++) {
		for (; j < N; j++) {
			if (V[A[j]])
				break;
			V[A[j]] = true;
		}
		answer += j - i;
		V[A[i]] = false;
	}
	cout << answer << '\n';
	return 0;
}
