#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<vector<int>> arr(21, vector<int>(21, 0));
int answer;

vector<vector<int>> move(vector<vector<int>> &t, int dir)
{
    vector<vector<int>> m(21, vector<int>(21, 0));
    vector<vector<int>> v(21, vector<int>(21, 0));

    if (dir == 0)
    {
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            for (int k = 0; k < n; k++)
            {
                if (t[i][k] != 0)
                {
                    if (v[i][j] == 0)
                    {
                        v[i][j]++;
                        m[i][j] = t[i][k];
                    }
                    else if (v[i][j] == 1 && m[i][j] == t[i][k])
                    {
                        v[i][j]++;
                        m[i][j] += t[i][k];
                        j++;
                    }
                    else
                    {
                        j++;
                        v[i][j]++;
                        m[i][j] = t[i][k];
                    }
                }
            }
        }
    }
    else if (dir == 1)
    {
        for (int i = 0; i < n; i++)
        {
            int j = n - 1;
            for (int k = n - 1; k >= 0; k--)
            {
                if (t[i][k] != 0)
                {
                    if (v[i][j] == 0)
                    {
                        v[i][j]++;
                        m[i][j] = t[i][k];
                    }
                    else if (v[i][j] == 1 && m[i][j] == t[i][k])
                    {
                        v[i][j]++;
                        m[i][j] += t[i][k];
                        j--;
                    }
                    else
                    {
                        j--;
                        v[i][j]++;
                        m[i][j] = t[i][k];
                    }
                }
            }
        }
    }
    else if (dir == 2)
    {
        for (int i = 0; i < n; i++)
        {
            int j = n - 1;
            for (int k = n - 1; k >= 0; k--)
            {
                if (t[k][i] != 0)
                {
                    if (v[j][i] == 0)
                    {
                        v[j][i]++;
                        m[j][i] = t[k][i];
                    }
                    else if (v[j][i] == 1 && m[j][i] == t[k][i])
                    {
                        v[j][i]++;
                        m[j][i] += t[k][i];
                        j--;
                    }
                    else
                    {
                        j--;
                        v[j][i]++;
                        m[j][i] = t[k][i];
                    }
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            for (int k = 0; k < n; k++)
            {
                if (t[k][i] != 0)
                {
                    if (v[j][i] == 0)
                    {
                        v[j][i]++;
                        m[j][i] = t[k][i];
                    }
                    else if (v[j][i] == 1 && m[j][i] == t[k][i])
                    {
                        v[j][i]++;
                        m[j][i] += t[k][i];
                        j++;
                    }
                    else
                    {
                        j++;
                        v[j][i]++;
                        m[j][i] = t[k][i];
                    }
                }
            }
        }
    }
    return (m);
}

void dfs(vector<vector<int>> &t, int index)
{
    if (index >= 5)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                answer = max(answer, t[i][j]);
                //cout << t[i][j] << ' ';
            }
            //cout << "\n";
        }
        //cout << "\n";
        return;
    }
    vector<vector<int>> tmp = move(t, 0);
    dfs(tmp, index + 1);
    tmp = move(t, 1);
    dfs(tmp, index + 1);
    tmp = move(t, 2);
    dfs(tmp, index + 1);
    tmp = move(t, 3);
    dfs(tmp, index + 1);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    dfs(arr, 0);
    cout << answer << '\n';
    return (0);
}