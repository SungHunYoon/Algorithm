#include <iostream>
#include <cmath>

using namespace std;

int D;
string S;
long X, Y, stdX, stdY;

void DQ(int idx, long x, long y) {
	if (idx >= D) {
		stdX = x;
		stdY = y;
		return;
	}
	int num = S[idx] - '0';
	long p = pow(2, D - idx);
	if (num == 1) {
		DQ(idx + 1, x, y + p / 2);
	} else if (num == 2) {
		DQ(idx + 1, x, y);
	} else if (num == 3) {
		DQ(idx + 1, x + p / 2, y);
	} else {
		DQ(idx + 1, x + p / 2, y + p / 2);
	}
}

void reverseDQ(string& s, int idx, long x, long y) {
	if (idx >= D) {
		return;
	}
	long p = pow(2, D - idx);
	if (p / 2 > x && p / 2 <= y) {
		s.push_back('1');
		reverseDQ(s, idx + 1, x, y - p / 2);
	} else if (p / 2 > x && p / 2 > y) {
		s.push_back('2');
		reverseDQ(s, idx + 1, x, y);
	} else if (p / 2 <= x && p / 2 > y) {
		s.push_back('3');
		reverseDQ(s, idx + 1, x - p / 2, y);
	} else {
		s.push_back('4');
		reverseDQ(s, idx + 1, x - p / 2, y - p / 2);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> D >> S >> X >> Y;
	DQ(0, 0, 0);
	long calX = stdX - Y;
	long calY = stdY + X;
	if (0 > calX || calX >= pow(2, D) || 0 > calY || calY >= pow(2, D)) {
		cout << "-1\n";
	} else {
		string answer;
		reverseDQ(answer, 0, calX, calY);
		cout << answer << '\n';
	}
	return 0;
}