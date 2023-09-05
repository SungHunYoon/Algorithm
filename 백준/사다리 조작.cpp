#include <iostream>
#include <vector>

using namespace std;

int check(vector<vector<bool>> &v, int n, int h)
{
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
    {
        c[i] = i;
        for (int j = 1; j <= h; j++)
        {
            if (v[c[i]][j])
                c[i]++;
            else if (v[c[i] - 1][j])
                c[i]--;
        }
        //cout << c[i] << '\n';
        if (c[i] != i)
            return (0);
    }
    return (1);
}

int recursive(vector<vector<bool>> &v, int n, int h, int h_index, int cnt)
{
    if (cnt >= 4)
        return (-1);
    else if (check(v, n, h) == 1)
        return (cnt);
    int ret = -1;
    for (int i = h_index; i <= h; i++)
    {
        for (int j = 1; j <= n - 1; j++)
        {
            if (!v[j][i] && !v[j - 1][i] && !v[j + 1][i])
            {
                v[j][i] = true;
                int tmp = recursive(v, n, h, i, cnt + 1);
                if (ret == -1 || (tmp != -1 && ret > tmp))
                    ret = tmp;
                v[j][i] = false;
            }
        }
    }
    return (ret);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, h;
    cin >> n >> m >> h;
    vector<vector<bool>> v (n + 1, vector<bool>(h + 1, false));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[b][a] = true;
    }
    cout << recursive(v, n, h, 1, 0) << '\n';
    return (0);
}