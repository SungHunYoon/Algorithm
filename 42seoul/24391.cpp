#include <iostream>

using namespace std;

int N, M;
int A[100001];
int P[100001];

int find(int idx) {
	if (idx == P[idx])
		return idx;
	P[idx] = find(P[idx]);
	return P[idx];
}

void makeUnion(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (a > b)
		P[a] = b;
	else
		P[b] = a;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		P[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		makeUnion(a, b);
	}
	int answer = 0;
	int prev = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (prev != 0) {
			if (find(prev) != find(A[i]))
				answer++;
		}
		prev = A[i];
	}
	cout << answer << '\n';
	return 0;
}