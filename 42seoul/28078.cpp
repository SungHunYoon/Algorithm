#include <iostream>
#include <deque>

using namespace std;

int Q;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> Q;
	deque<char> q;
	int state = 0, wCnt = 0, bCnt = 0;
	while (Q--) {
		string s;
		char c;
		cin >> s;
		if (s == "push") {
			cin >> c;
			q.push_front(c);
			if (c == 'b') {
				bCnt++;
			} else {
				wCnt++;
			}
		} else if (s == "count") {
			cin >> c;
			if (c == 'b') {
				cout << bCnt << '\n';
			} else {
				cout << wCnt << '\n';
			}
		} else if (s == "pop") {
			if (!q.empty()) {
				if (q.back() == 'b') {
					bCnt--;
				} else {
					wCnt--;
				}
				q.pop_back();
			}
		} else {
			cin >> c;
			if (c == 'l') {
				state--;
				if (state < 0) state = 3;
			} else {
				state++;
				if (state > 3) state = 0;
			}
		}
		if (state == 1) {
			while (!q.empty() && q.back() != 'w') {
				bCnt--;
				q.pop_back();
			}
		} else if (state == 3) {
			while (!q.empty() && q.front() != 'w') {
				bCnt--;
				q.pop_front();
			}
		}
	}

	return 0;
}