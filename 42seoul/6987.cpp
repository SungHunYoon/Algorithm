#include <iostream>
#include <vector>

using namespace std;

int A[18];

int dfs(vector<int> &v, int index);

int comb(vector<int> &v, vector<int> c, int index) {
	if (6 <= index + c.size() + 1) {
		for (int i = 0; i < c.size(); i++) {
			v[index * 3 + c[i]]++;
			v[(index + i + 1) * 3 + (3 - c[i] - 1)]++; 
		}
		if (v[index * 3] == A[index * 3] && \
			v[index * 3 + 1] == A[index * 3 + 1] && \
			v[index * 3 + 2] == A[index * 3 + 2]) {
			if (dfs(v, index + 1))
				return 1;
		}
		for (int i = 0; i < c.size(); i++) {
			v[index * 3 + c[i]]--;
			v[(index + i + 1) * 3 + (3 - c[i] - 1)]--; 
		}
		return 0;
	}
	for (int i = 0; i < 3; i++) {
		c.push_back(i);
		if (comb(v, c, index))
			return 1;
		c.pop_back();
	}
	return 0;
}

int dfs(vector<int> &v, int index) {
	if (index >= 6) {
		for (int i = 0; i < 18; i++) { 
			if (v[i] != A[i])
				return 0;
		}
		return 1;
	}
	vector<int> c;
	if (comb(v, c, index))
		return 1;
	return 0;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 18; j++)
			cin >> A[j];
		vector<int> v(18);
		cout << dfs(v, 0) << ' ';
 	}
	
	return 0;
}