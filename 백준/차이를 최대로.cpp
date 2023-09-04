#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void perm(vector<vector<int>> &arr, vector<bool> v, vector<int> t, int index, int n)
{
    if (n == index)
    {
        arr.push_back(t);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] == false)
        {
            v[i] = true;
            t.push_back(i);
            perm(arr, v, t, index + 1, n);
            t.erase(t.begin() + index);
            v[i] = false;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> p;
    vector<bool> v (n, false);
    vector<int> t;
    perm(p, v, t, 0, n);
    int answer = -1000000000;
    for (int i = 0; i < p.size(); i++)
    {
        int tmp = 0;
        for (int j = 0; j < p[i].size() - 1; j++)
            tmp += abs(arr[p[i][j]] - arr[p[i][j + 1]]);
        if (tmp > answer)
            answer = tmp;
    }
    cout << answer << '\n';
    return (0);
}