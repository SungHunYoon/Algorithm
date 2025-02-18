#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, Q;
ii T[100001];
ii A[100001];
int answer[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> T[i].first >> T[i].second;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(T, T + N);
	sort(A, A + Q);
	priority_queue<int, vector<int>, greater<int>> pq;
	int tIdx = 0, aIdx = 0;
	for (int i = 0; i <= 1000000; i++) {
		while (tIdx < N && T[tIdx].first == i) {
			pq.push(T[tIdx].second);
			tIdx++;
		}
		while (!pq.empty() && pq.top() < i)
			pq.pop();
		while (aIdx < Q && A[aIdx].first == i) {
			answer[A[aIdx].second] = pq.size();
			aIdx++;
		}
	}
	for (int i = 0; i < Q; i++)
		cout << answer[i] << '\n';
	return 0;
}