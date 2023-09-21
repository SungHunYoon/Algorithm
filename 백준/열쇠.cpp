#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

int t, h, w;
char arr[101][101];

int nx[4] = {1, -1, 0, 0};
int ny[4] = {0, 0, 1, -1};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> h >> w;
        deque<pair<int, pair<int, int>>> dq;
        bool visit[101][101] = { false, };
        bool key[26] = { false, };
        for (int j = 0; j < h; j++)
        {
            for (int k = 0; k < w; k++)
            {
                cin >> arr[j][k];
                if (j == 0 || j == h - 1 || k == 0 || k == w - 1)
                {
                    if (arr[j][k] != '*')
                    {
                        visit[j][k] = true;
                        if (arr[j][k] == '.' || arr[j][k] == '$' || ('a' <= arr[j][k] && arr[j][k] <= 'z'))
                            dq.push_front({-arr[j][k], {k, j}});
                        else
                            dq.push_back({-arr[j][k], {k, j}});
                    }
                }
            }
        }
        string s;
        cin >> s;
        if (s != "0")
        {
            for (int j = 0; j < s.length(); j++)
                key[s[j] - 'a'] = true;
        }

        int answer = 0;
        int cnt = 0;
        while (!dq.empty())
        {
            char curC = -dq.front().first;
            pair<int, int> x = dq.front().second;
            dq.pop_front();
            if ('A' <= curC && curC <= 'Z')
            {
                if (!key[curC - 'A'])
                {
                    dq.push_back({-curC, x});
                    cnt++;
                    if (cnt == dq.size())
                        break;
                    continue;
                }
            }
            else if ('a' <= curC && curC <= 'z')
                key[curC - 'a'] = true;
            else if (curC == '$')
                answer++;
            cnt = 0;
            for (int j = 0; j < 4; j++)
            {
                int dx, dy;
                dx = x.first + nx[j];
                dy = x.second + ny[j];
                if (0 <= dx && dx < w && 0 <= dy && dy < h)
                {
                    if (!visit[dy][dx] && arr[dy][dx] != '*')
                    {
                        visit[dy][dx] = true;
                        if (arr[dy][dx] == '.' || arr[dy][dx] == '$' || ('a' <= arr[dy][dx] && arr[dy][dx] <= 'z'))
                            dq.push_front({-arr[dy][dx], {dx, dy}});
                        else
                            dq.push_back({-arr[dy][dx], {dx, dy}});
                    }
                }
            }
        }
        cout << answer << '\n';
    }

    return (0);
}