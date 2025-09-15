#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
using ii = pair<int, int>;

int N, M, P, L, G;
set<ii> group[101];
map<int, set<int>> level;
int gT[100001];
int lT[100001];

void erase() {
	group[gT[P]].erase(group[gT[P]].find({lT[P], P}));
	auto it = level.find(lT[P]);
	it->second.erase(it->second.find(P));
	if (it->second.size() == 0) {
		level.erase(it);
	}
	lT[P] = 0;
	gT[P] = 0;
}

void add() {
	if (lT[P] || gT[P]) {
		erase();
	}
	gT[P] = G;
	lT[P] = L;
	group[G].insert({L, P});
	auto it = level.find(L);
	if (it == level.end()) {
		set<int> S;
		S.insert(P);
		level.insert({L, S});
	} else {
		it->second.insert(P);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> P >> L >> G;
		add();
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		string s;
		int x;
		cin >> s;
		if (s == "recommend") {
			cin >> G >> x;
			if (x == -1) {
				cout << group[G].begin()->second << '\n';
			} else {
				cout << prev(group[G].end())->second << '\n';
			}
		} else if (s == "recommend2") {
			cin >> x;
			if (x == -1) {
				cout << *(level.begin()->second.begin()) << '\n';
			} else {
				cout << *prev(prev(level.end())->second.end()) << '\n';
			}
		} else if (s == "recommend3") {
			cin >> x >> L;
			if (x == -1) {
				auto it = level.lower_bound(L);
				if (it == level.begin()) {
					cout << "-1\n";
				} else {
					cout << *prev(prev(it)->second.end()) << '\n';
				}
			} else {
				auto it = level.lower_bound(L);
				if (it == level.end()) {
					cout << "-1\n";
				} else {
					cout << *(it->second.begin()) << '\n';
				}
			}
		} else if (s == "add") {
			cin >> P >> L >> G;
			add();
		} else {
			cin >> P;
			erase();
		}
	}
	return 0;
}