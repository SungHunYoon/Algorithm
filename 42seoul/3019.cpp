#include <iostream>
#include <vector>

using namespace std;

int C, P;
int A[101];
vector<vector<int>> B[7];

vector<vector<int>> makeBlock1() {
	vector<vector<int>> b;
	b.push_back(vector<int>(1));
	b.push_back(vector<int>(4));
	return b;
}

vector<vector<int>> makeBlock2() {
	vector<vector<int>> b;
	b.push_back(vector<int>(2));
	return b;
}

vector<vector<int>> makeBlock3() {
	vector<vector<int>> b;
	b.push_back(vector<int>(3));
	b.push_back(vector<int>(2));
	b[0][2] = 1;
	b[1][1] = -1;
	return b;
}

vector<vector<int>> makeBlock4() {
	vector<vector<int>> b;
	b.push_back(vector<int>(3));
	b.push_back(vector<int>(2));
	b[0][1] = -1;
	b[1][1] = 1;
	return b;
}

vector<vector<int>> makeBlock5() {
	vector<vector<int>> b;
	b.push_back(vector<int>(3));
	b.push_back(vector<int>(2));
	b.push_back(vector<int>(3));
	b.push_back(vector<int>(2));
	b[1][1] = 1;
	b[2][1] = -1; b[2][2] = 1;
	b[3][1] = -1;
	return b;
}

vector<vector<int>> makeBlock6() {
	vector<vector<int>> b;
	b.push_back(vector<int>(3));
	b.push_back(vector<int>(2));
	b.push_back(vector<int>(3));
	b.push_back(vector<int>(2));
	b[2][1] = 1;
	b[3][1] = -2;
	return b;
}

vector<vector<int>> makeBlock7() {
	vector<vector<int>> b;
	b.push_back(vector<int>(3));
	b.push_back(vector<int>(2));
	b.push_back(vector<int>(3));
	b.push_back(vector<int>(2));
	b[1][1] = 2;
	b[2][2] = -1;
	return b;
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> C >> P;
	for (int i = 0; i < C; i++)
		cin >> A[i];
	P--;
	B[0] = makeBlock1(); B[1] = makeBlock2();
	B[2] = makeBlock3(); B[3] = makeBlock4();
	B[4] = makeBlock5(); B[5] = makeBlock6();
	B[6] = makeBlock7();
	int answer = 0;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < B[P].size(); j++) {
			int prev = A[i];
			bool flag = true;
			for (int k = 0; k < B[P][j].size(); k++) {
				if (B[P][j][k] != A[i + k] - prev || i + k >= C) {
					flag = false;
					break;
				}
				prev = A[i + k];
			}
			if (flag) answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}