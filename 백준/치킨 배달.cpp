#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void comb(vector<vector<int>> &arr, vector<int> t, int index, int r, int n)
{
    if (r == 0)
    {
        arr.push_back(t);
        return;
    }
    else if (index == n)
        return;
    comb(arr, t, index + 1, r, n);
    t.push_back(index);
    comb(arr, t, index + 1, r - 1, n);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> home;
    vector<pair<int, int>> chicken;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
                home.push_back({j + 1, i + 1});
            else if (x == 2)
                chicken.push_back({j + 1, i + 1});
        }
    }

    vector<vector<int>> cb;
    vector<int> t;
    comb(cb, t, 0, m, chicken.size());
    int answer = 1000000000;
    for (int i = 0; i < cb.size(); i++)
    {
        int distance = 0;
        for (int j = 0; j < home.size(); j++)
        {
            int min = 1000000000;
            for (int k = 0; k < cb[i].size(); k++)
            {
                int tmp = abs(chicken[cb[i][k]].first - home[j].first) + abs(chicken[cb[i][k]].second - home[j].second);
                if (min > tmp)
                    min = tmp;
            }
            distance += min;
        }
        if (answer > distance)
            answer = distance;
    }
    cout << answer << '\n';
    return (0);
}