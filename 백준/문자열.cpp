#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    string a;
    string b;
    vector<int> answer;

    cin >> a;
    cin >> b;
    for (int i = 0; i <= b.size() - a.size(); i++)
    {
        string tmp = b.substr(i);
        int cnt = 0;
        for (int j = 0; j < a.size(); j++)
        {
            if (tmp[j] != a[j])
                cnt++;
        }
        answer.push_back(cnt);
    }
    sort(answer.begin(), answer.end());
    cout << answer[0] << endl;
    return (0);
}