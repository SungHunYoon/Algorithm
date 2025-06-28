#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Ingrediant {
	private:
		int I[4][4];
		char E[4][4];

	public:
		int getImpactValue(int x, int y) {
			return I[x][y];
		}

		char getElementValue(int x, int y) {
			return E[x][y];
		}

		void setImpactValue(int x, int y, int i) {
			I[x][y] = i;
		}

		void setElementValue(int x, int y, char e) {
			E[x][y] = e;
		}

		void rotate() {
			int tI[4][4];
			char tE[4][4];
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					tI[j][4 - i - 1] = I[i][j];
					tE[j][4 - i - 1] = E[i][j]; 
				}
			}
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					I[i][j] = tI[i][j];
					E[i][j] = tE[i][j];
				}
			}
		}

		friend ostream& operator<<(ostream &out, Ingrediant& rhs) {
			out << "========= I =========\n";
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					out << rhs.I[i][j] << ' ';
				}
				out << '\n';
			}
			out << "========= E =========\n";
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					out << rhs.E[i][j] << ' ';
				}
				out << '\n';
			}
			return out;
		}
};

int N;
int A[5][5], B[5][5];
Ingrediant ingrediant[10];
bool visited[10];

int calScore() {
	int ret = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (B[i][j] == 'R') {
				ret += A[i][j] * 7;
			} else if (B[i][j] == 'B') {
				ret += A[i][j] * 5;
			} else if (B[i][j] == 'G') {
				ret += A[i][j] * 3;
			} else if (B[i][j] == 'Y') {
				ret += A[i][j] * 2;
			}
		}
	}
	return ret;
}

int dfs2(vector<int> &v, int idx) {
	if (idx >= 3) {
		return calScore();
	}
	int ret = 0;
	int tA[5][5], tB[5][5];
	copy(&A[0][0], &A[5][0], &tA[0][0]);
	copy(&B[0][0], &B[5][0], &tB[0][0]);
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = j; l < j + 4; l++) {
					for (int m = k; m < k + 4; m++) {
						A[l][m] += ingrediant[v[idx]].getImpactValue(l - j, m - k);
						A[l][m] = max(0, A[l][m]);
						A[l][m] = min(9, A[l][m]);
						char c = ingrediant[v[idx]].getElementValue(l - j, m - k);
						if (c != 'W')
							B[l][m] = c;
					}
				}
				ret = max(ret, dfs2(v, idx + 1));
				for (int l = j; l < j + 4; l++) {
					for (int m = k; m < k + 4; m++) {
						A[l][m] = tA[l][m];
						B[l][m] = tB[l][m];
					}
				}
			}
		}
		ingrediant[v[idx]].rotate();
	}
	return ret;
}

int dfs(vector<int> &v, int cnt) {
	if (cnt >= 3) {
		return dfs2(v, 0);
	}
	int ret = 0;
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		v.push_back(i);
		ret = max(ret, dfs(v, cnt + 1));
		v.pop_back();
		visited[i] = false;
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				int n;
				cin >> n;
				ingrediant[i].setImpactValue(j, k, n);
			}
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				char c;
				cin >> c;
				ingrediant[i].setElementValue(j, k, c);
			}
		}
	}
	fill(&B[0][0], &B[5][0], 'W');
	vector<int> v;
	cout << dfs(v, 0) << '\n';
	return 0;
}