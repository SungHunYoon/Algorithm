#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int h, w;
pair<int, int> s;
pair<int, int> e;
int arr[1001][1001];
bool visit[1001][1001];

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    cin >> h >> w;
    cin >> s.second >> s.first;
    cin >> e.second >> e.first;

    queue<pair<int, int>> q;
    visit[s.second + h - 1][s.first + w - 1] = true;
    q.push({s.first + w - 1, s.second + h - 1});
    int answer = 1000000000;
    int cnt = 0;
    int flag = 0;
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            pair<int, int> x = q.front();
            q.pop();
            if (x.first == e.first + w - 1 && x.second == e.second + h - 1)
            {
                answer = min(answer, cnt);
                flag = 1;
                break;
            }
            for (int j = 0; j < 4; j++)
            {
                int dx, dy;
                dx = x.first + nx[j];
                dy = x.second + ny[j];
                if (1 <= dx - w + 1 && dx <= m && 1 <= dy - h + 1 && dy <= n)
                {
                    if (j < 2)
                    {
                        int k;
                        for (k = dy - h + 1; k <= dy; k++)
                        {
                            if (j == 0)
                            {
                                if (arr[k][dx] != 0)
                                    break;
                            }
                            else
                            {
                                if (arr[k][dx - w + 1] != 0)
                                    break;
                            }
                        }
                        if (k - 1 != dy)
                            continue;
                    }
                    else if (j < 4)
                    {
                        int k;
                        for (k = dx - w + 1; k <= dx; k++)
                        {
                            if (j == 3)
                            {
                                if (arr[dy][k] != 0)
                                    break;
                            }
                            else
                            {
                                if (arr[dy - h + 1][k] != 0)
                                    break;
                            }
                        }
                        if (k - 1 != dx)
                            continue;
                    }
                    if (!visit[dy][dx])
                    {
                        visit[dy][dx] = true;
                        q.push({dx, dy});
                    }
                }
            }
        }
        if (flag == 1)
            break;
        cnt++;
    }
    if (answer == 1000000000)
        cout << "-1\n";
    else
        cout << answer << '\n';
    return (0);
}