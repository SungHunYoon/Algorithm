#include <iostream>
#include <map>

using namespace std;

string S1, S2;

map<string, int> stringM;
map<int, pair<string, int>> intM;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S1 >> S2;

	stringM.insert({"I", 1}); stringM.insert({"V", 5});
	stringM.insert({"X", 10}); stringM.insert({"L", 50});
	stringM.insert({"C", 100}); stringM.insert({"D", 500});
	stringM.insert({"M", 1000}); stringM.insert({"IV", 4});
	stringM.insert({"IX", 9}); stringM.insert({"XL", 40});
	stringM.insert({"XC", 90}); stringM.insert({"CD", 400});
	stringM.insert({"CM", 900});

	intM.insert({1, {"I", 3}}); intM.insert({5, {"V", 1}});
	intM.insert({10, {"X", 3}}); intM.insert({50, {"L", 1}});
	intM.insert({100, {"C", 3}}); intM.insert({500, {"D", 1}});
	intM.insert({1000, {"M", 3}}); intM.insert({4, {"IV", 1}});
	intM.insert({9, {"IX", 1}}); intM.insert({40, {"XL", 1}});
	intM.insert({90, {"XC", 1}}); intM.insert({400, {"CD", 1}});
	intM.insert({900, {"CM", 1}});

	int answer = 0;
	int i;
	for (i = 1; i < S1.size(); i++) {
		string s = S1.substr(i - 1, 2);
		auto it = stringM.find(s);
		if (it != stringM.end()) {
			answer += it->second;
			i++;
		}
		else
			answer += stringM[S1.substr(i - 1, 1)];
	}
	if (i - 1 < S1.size())
		answer += stringM[S1.substr(i - 1, 1)];
	for (i = 1; i < S2.size(); i++) {
		string s = S2.substr(i - 1, 2);
		auto it = stringM.find(s);
		if (it != stringM.end()) {
			answer += it->second;
			i++;
		}
		else
			answer += stringM[S2.substr(i - 1, 1)];
	}
	if (i - 1 < S2.size())
		answer += stringM[S2.substr(i - 1, 1)];
	cout << answer << '\n';
	string sAnswer;
	while (answer > 0) {
		for (auto it = intM.rbegin(); it != intM.rend(); it++) {
			if (answer - it->first >= 0) {
				sAnswer += it->second.first;
				answer -= it->first;
				it->second.second--;
				if (it->second.second <= 0)
					intM.erase(--it.base());
				break;
			}
		}
	}
	cout << sAnswer << '\n';
	return 0;
}