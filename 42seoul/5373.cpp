#include <iostream>

using namespace std;

int T, N;

class Face {
	private:
		char A[3][3];
		char Z[3][3];
		Face *L, *R, *F, *B;
		int cl, cr, cf, cb;
		int ccl, ccr, ccf, ccb;

	public:
		Face(char color) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					A[i][j] = color;
			}
		}

		void setLeft(Face *L, int cl, int ccl) {
			this->L = L;
			this->cl = cl;
			this->ccl = ccl;
		}

		void setRight(Face *R, int cr, int ccr) {
			this->R = R;
			this->cr = cr;
			this->ccr = ccr;
		}

		void setFront(Face *F, int cf, int ccf) {
			this->F = F;
			this->cf = cf;
			this->ccf = ccf;
		}

		void setBack(Face *B, int cb, int ccb) {
			this->B = B;
			this->cb = cb;
			this->ccb = ccb;
		}

		void getTopLine(int n, char *line) {
			if (n == 0) {
				for (int i = 0; i < 3; i++)
					line[i] = A[0][i];
			} else if (n == 1) {
				for (int i = 0; i < 3; i++)
					line[i] = A[2][i];
			} else if (n == 2) {
				for (int i = 0; i < 3; i++)
					line[i] = A[i][0];
			} else if (n == 3) {
				for (int i = 0; i < 3; i++)
					line[i] = A[i][2];
			} else if (n == 4) {
				for (int i = 0; i < 3; i++)
					line[i] = A[0][2 - i];
			} else if (n == 5) {
				for (int i = 0; i < 3; i++)
					line[i] = A[2][2 - i];
			} else if (n == 6) {
				for (int i = 0; i < 3; i++)
					line[i] = A[2 - i][0];
			} else {
				for (int i = 0; i < 3; i++)
					line[i] = A[2 - i][2];
			}
		}

		void setTopLine(int n, char *sLine, char *gLine) {
			getTopLine(n, gLine);
			int idx = n % 4;
			if (idx == 0) {
				for (int i = 0; i < 3; i++)
					A[0][i] = sLine[i];
			} else if (idx == 1) {
				for (int i = 0; i < 3; i++)
					A[2][i] = sLine[i];
			} else if (idx == 2) {
				for (int i = 0; i < 3; i++)
					A[i][0] = sLine[i];
			} else {
				for (int i = 0; i < 3; i++)
					A[i][2] = sLine[i];
			}
		}

		void rotateClock() {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					Z[j][2 - i] = A[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					A[i][j] = Z[i][j];
			}
			char C[3], D[3];
			F->getTopLine(cf, C);
			L->setTopLine(cl, C, D);
			B->setTopLine(cb, D, C);
			R->setTopLine(cr, C, D);
			F->setTopLine(cf, D, C);
		}

		void rotateClockWise() {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					Z[2 - j][i] = A[i][j];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					A[i][j] = Z[i][j];
				}
			}
			char C[3], D[3];
			F->getTopLine(ccf, C);
			R->setTopLine(ccr, C, D);
			B->setTopLine(ccb, D, C);
			L->setTopLine(ccl, C, D);
			F->setTopLine(ccf, D, C);
		}

		friend ostream& operator<<(ostream& out, const Face& face) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					out << face.A[i][j];
				out << '\n';
			}
			return out;
		}
};

class Cube {
	private:
		enum {
			UP = 0,
			DOWN,
			FRONT,
			BACK,
			LEFT,
			RIGHT,
		};

		Face *A[6];

		int getIdx(char a) {
			if (a == 'U') return 0;
			else if (a == 'D') return 1;
			else if (a == 'F') return 2;
			else if (a == 'B') return 3;
			else if (a == 'L') return 4;
			else return 5;
		}

	public:
		Cube(Face &U, Face &D, Face &F, Face &B, Face &L, Face &R) {
			A[UP] = &U; A[DOWN] = &D; A[FRONT] = &F;
			A[BACK] = &B; A[LEFT] = &L; A[RIGHT] = &R;

			A[UP]->setFront(A[FRONT], 0, 0); A[UP]->setBack(A[BACK], 0, 0);
			A[UP]->setLeft(A[LEFT], 0, 0); A[UP]->setRight(A[RIGHT], 0, 0);

			A[DOWN]->setFront(A[BACK], 1, 1); A[DOWN]->setBack(A[FRONT], 1, 1);
			A[DOWN]->setLeft(A[LEFT], 1, 1); A[DOWN]->setRight(A[RIGHT], 1, 1);

			A[FRONT]->setFront(A[DOWN], 0, 4); A[FRONT]->setBack(A[UP], 1, 5);
			A[FRONT]->setLeft(A[LEFT], 7, 3); A[FRONT]->setRight(A[RIGHT], 6, 2);

			A[BACK]->setFront(A[DOWN], 5, 1); A[BACK]->setBack(A[UP], 4, 0);
			A[BACK]->setLeft(A[RIGHT], 3, 7); A[BACK]->setRight(A[LEFT], 2, 6);

			A[LEFT]->setFront(A[DOWN], 6, 2); A[LEFT]->setBack(A[UP], 2, 6);
			A[LEFT]->setLeft(A[BACK], 7, 7); A[LEFT]->setRight(A[FRONT], 2, 2);

			A[RIGHT]->setFront(A[DOWN], 3, 7); A[RIGHT]->setBack(A[UP], 7, 3);
			A[RIGHT]->setLeft(A[FRONT], 3, 3); A[RIGHT]->setRight(A[BACK], 6, 6);
		}

		void rotate(char a, char rotate) {
			int faceIdx = getIdx(a);
			if (rotate == '+')
				A[faceIdx]->rotateClock();
			else
				A[faceIdx]->rotateClockWise();
		}

		friend ostream& operator<<(ostream& out, const Cube& cube) {
			out << *(cube.A[0]);
			return out;
		}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		Face U = Face('w'), D = Face('y'), F = Face('r'), B = Face('o'), L = Face('g'), R = Face('b');
		Cube C = Cube(U, D, F, B, L, R);
		cin >> N;
		while (N--) {
			char a, b;
			cin >> a >> b;
			C.rotate(a, b);
		}
		cout << C;
	}

	return 0;
}