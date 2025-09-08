#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int N, M;
int T[100001];
set<int> P[100001];
map<int, int> L;

void add(int p, int l) {
	T[p] = l;
	P[l].insert(p);
	L[l]++;
}

void erase(int p, int l) {
	P[l].erase(P[l].find(p));
	auto it = L.find(l);
	if (--it->second == 0) {
		L.erase(it);
	}
	T[p] = 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int p, l;
		cin >> p >> l;
		add(p, l);
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		string s;
		cin >> s;
		int p, l;
		if (s == "add") {
			cin >> p >> l;
			if (T[p]) {
				erase(p, l);
			}
			add(p, l);
		} else if (s == "recommend") {
			cin >> p;
			if (p == -1) {
				auto it = L.begin();
				cout << *(P[it->first].begin()) << '\n';
			} else {
				auto it = prev(L.end());
				cout << *(prev(P[it->first].end())) << '\n';
			}
		} else {
			cin >> p;
			erase(p, T[p]);
		}
	}

	return 0;
}