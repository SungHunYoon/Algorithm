#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

double ax, ay, az, bx, by, bz, cx, cy, cz;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> ax >> ay >> az >> bx >> by >> bz >> cx >> cy >> cz;
	int T = 1000000;
	double answer = 1e9;
	while (T--) {
		double px = (2 * ax + bx) / 3;
		double py = (2 * ay + by) / 3;
		double pz = (2 * az + bz) / 3;
		double qx = (2 * bx + ax) / 3;
		double qy = (2 * by + ay) / 3;
		double qz = (2 * bz + az) / 3;

		double lowD = sqrt(pow(ax - cx, 2) + pow(ay - cy, 2) + pow(az - cz, 2));
		double pD = sqrt(pow(px - cx, 2) + pow(py - cy, 2) + pow(pz - cz, 2));
		double qD = sqrt(pow(qx - cx, 2) + pow(qy - cy, 2) + pow(qz - cz, 2));
		double highD = sqrt(pow(bx - cx, 2) + pow(by - cy, 2) + pow(bz - cz, 2));

		answer = min({answer, lowD, highD});

		if (pD >= qD) {
			ax = px;
			ay = py;
			az = pz;
		} else {
			bx = qx;
			by = qy;
			bz = qz;
		}
	}
	cout.precision(6);
	cout << fixed << answer << '\n';
	return 0;
}