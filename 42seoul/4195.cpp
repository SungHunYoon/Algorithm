#include <iostream>
#include <map>

using namespace std;

int T, N;
int P[200001];
int S[200001];
string A, B;

int find(int idx) {
	if (idx == P[idx]) return idx;
	P[idx] = find(P[idx]);
	return P[idx];
}

void make_union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a < b) {
		P[b] = a;
		S[a] += S[b];
	}
	else {
		P[a] = b;
		S[b] += S[a];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= 200000; i++) {
			P[i] = i;
			S[i] = 1;
		}
		map<string, int> m;
		int idx = 1;
		for (int i = 0; i < N; i++) {
			cin >> A >> B;
			if (m.find(A) == m.end())
				m.insert({A, idx++});
			if (m.find(B) == m.end())
				m.insert({B, idx++});
			int aIdx = m[A];
			int bIdx = m[B];
			make_union(aIdx, bIdx);
			cout << S[find(aIdx)] << '\n';
		}
	}

	return 0;
}