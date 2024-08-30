#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;
using dii = tuple<double, int, int>;

int N, M, A, B;
ii V[1001];
vector<dii> E;
int P[1001];
int cnt;
double answer;

int find(int idx) {
	if (P[idx] == idx)
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
	for (int i = 1; i <= N; i++)
		cin >> V[i].first >> V[i].second;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		if (find(A) != find(B)) {
			make_union(A, B);
			cnt++;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			double d = sqrt(pow(V[i].first - V[j].first, 2) + pow(V[i].second - V[j].second, 2));
			E.push_back({d, i, j});
		}
	}
	sort(E.begin(), E.end());
	for (auto [d, a, b] : E) {
		if (find(a) != find(b)) {
			make_union(a, b);
			cnt++;
			answer += d;
			if (cnt == N - 1)
				break;
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << answer << '\n';
	return 0;
}