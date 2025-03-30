#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

double aX[2], aY[2], bX[2], bY[2];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> aX[0] >> aY[0] >> aX[1] >> aY[1] >> bX[0] >> bY[0] >> bX[1] >> bY[1];
	double answer = 1e9;
	int T = 1000000;
	while (T--) {
		double pX1 = (2 * aX[0] + aX[1]) / 3;
		double pY1 = (2 * aY[0] + aY[1]) / 3;
		double qX1 = (2 * aX[1] + aX[0]) / 3;
		double qY1 = (2 * aY[1] + aY[0]) / 3;
		double pX2 = (2 * bX[0] + bX[1]) / 3;
		double pY2 = (2 * bY[0] + bY[1]) / 3;
		double qX2 = (2 * bX[1] + bX[0]) / 3;
		double qY2 = (2 * bY[1] + bY[0]) / 3;

		double lowD = sqrt(pow(aX[0] - bX[0], 2) + pow(aY[0] - bY[0], 2));
		double pD = sqrt(pow(pX1 - pX2, 2) + pow(pY1 - pY2, 2));
		double qD = sqrt(pow(qX1 - qX2, 2) + pow(qY1 - qY2, 2));
		double highD = sqrt(pow(aX[1] - bX[1], 2) + pow(aY[1] - bY[1], 2));

		answer = min({answer, lowD, highD});

		if (pD >= qD) {
			aX[0] = pX1;
			aY[0] = pY1;
			bX[0] = pX2;
			bY[0] = pY2;
		} else {
			aX[1] = qX1;
			aY[1] = qY1;
			bX[1] = qX2;
			bY[1] = qY2;
		}
	}
	cout.precision(6);
	cout << fixed << answer << '\n';
	return 0;
}