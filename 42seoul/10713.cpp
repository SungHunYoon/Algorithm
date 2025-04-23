#include <iostream>

using namespace std;

int N, M;
int A, B, C, P[100001], D[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= M; i++)
		cin >> P[i];
	for (int i = 2; i <= M; i++) {
		D[min(P[i - 1], P[i])] += 1;
		D[max(P[i - 1], P[i])] -= 1;
	}
	long answer = 0;
	for (int i = 1; i <= N - 1; i++) {
		cin >> A >> B >> C;
		D[i] += D[i - 1];
		long ticket = (long)A * D[i];
		long card = (long)B * D[i] + C;
		if (ticket > card)
			answer += card;
		else
			answer += ticket;
	}
	cout << answer << '\n';
	return 0;
}