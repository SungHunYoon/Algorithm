#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
using iii = tuple<int, int, int>;

int N, C;
int P[1001];
vector<iii> V;

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
	if (a > b)
		P[b] = a;
	else
		P[a] = b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> C;
			if (i == j) continue;
			V.push_back({C, i, j});
		}
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < N; i++)
		P[i] = i;
	long answer = 0;
	int cnt = 0;
	for (int i = 0; i < V.size(); i++) {
		int a = get<1>(V[i]);
		int b = get<2>(V[i]);
		if (find(P[a]) != find(P[b])) {
			make_union(P[a], P[b]);
			answer += get<0>(V[i]);
			cnt++;
			if (cnt == N - 1)
				break;
		}
	}
	cout << answer << '\n';
	return 0;
}