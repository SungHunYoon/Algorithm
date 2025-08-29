#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int N, M;
map<string, int> name;
string rName[1001];
int inDegree[1001];
vector<int> V[1001];
map<string, set<string>> answer;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		name.insert({s, i});
		rName[i] = s;
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		string a, b;
		cin >> a >> b;
		V[name[b]].push_back(name[a]);
		inDegree[name[a]]++;
	}
	queue<int> q;
	set<string> A;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i]) continue;
		q.push(i);
		A.insert(rName[i]);
	}
	while (!q.empty()) {
		int t = q.front(); q.pop();
		if (V[t].empty()) {
			answer[rName[t]] = set<string>();
		}
		for (auto v : V[t]) {
			if (--inDegree[v]) continue;
			answer[rName[t]].insert(rName[v]);
			q.push(v);
		}
	}
	cout << A.size() << '\n';
	for (auto a : A) {
		cout << a << ' ';
	}
	cout << '\n';
	for (auto [n, s] : answer) {
		cout << n << ' ' << s.size() << ' ';
		for (auto sn : s) {
			cout << sn << ' ';
		}
		cout << '\n';
	}
	return 0;
}