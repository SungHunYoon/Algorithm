#include <iostream>
#include <vector>

using namespace std;

int N, cnt, answer;
vector<int> V[100001];

void inorder(int idx) {
	if (V[idx][0] != -1) {
		inorder(V[idx][0]);
		answer++;
	}
	cnt++;
	if (V[idx][1] != -1) {
		inorder(V[idx][1]);
		answer++;
	}
	if (cnt < N)
		answer++;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int n, a, b;
		cin >> n >> a >> b;
		V[n].push_back(a);
		V[n].push_back(b);
	}
	inorder(1);
	cout << answer << '\n';
	return 0;
}