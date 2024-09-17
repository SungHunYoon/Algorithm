#include <iostream>
#include <set>

using namespace std;

int N, M, U, V;
int P[100001];

int find(int idx) {
	if (idx == P[idx])
		return idx;
	P[idx] = find(P[idx]);
	return P[idx];
}

void make_union(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b)
		return;
	if (a < b)
		P[b] = a;
	else
		P[a] = b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		P[i] = i;
	int answer = 0;
	for (int i = 0; i < M; i++) {
		cin >> U >> V;
		if (find(U) != find(V))
			make_union(U, V);
		else
			answer++;
	}
	set<int> S;
	for (int i = 1; i <= N; i++)
		S.insert(find(i));
	cout << answer + (S.empty() ? 0 : S.size() - 1) << '\n';
	return 0;
}