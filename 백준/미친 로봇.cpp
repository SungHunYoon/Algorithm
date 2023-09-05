#include <iostream>
#include <vector>

using namespace std;

double recursive(vector<int> &dir, vector<vector<bool>> &v, int n, int x, int y, double p, int index)
{
    if (v[y][x])
        return (p);
    else if (index == n)
        return (0);
    double ret = 0;
    v[y][x] = true;
    if (dir[0] != 0)
        ret += recursive(dir, v, n, x + 1, y, (p * dir[0] / (double)100), index + 1);
    if (dir[1] != 0)
        ret += recursive(dir, v, n, x - 1, y, (p * dir[1] / (double)100), index + 1);
    if (dir[2] != 0)
        ret += recursive(dir, v, n, x, y - 1, (p * dir[2] / (double)100), index + 1);
    if (dir[3] != 0)
        ret += recursive(dir, v, n, x, y + 1, (p * dir[3] / (double)100), index + 1);
    v[y][x] = false;
    return (ret);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> dir(4);
    vector<vector<bool>> v(n * 2 + 1, vector<bool>(n * 2 + 1, false));
    for (int i = 0; i < 4; i++)
        cin >> dir[i];
    
    cout.precision(10);
    cout << 1 - recursive(dir, v, n, n, n, 1, 0) << '\n';
    return (0);
}