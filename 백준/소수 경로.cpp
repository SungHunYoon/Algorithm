#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int t;
int a, b;
bool table[10000];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 2; i < 10000; i++)
    {
        if (table[i])
            continue;
        for (int j = i * 2; j < 10000; j += i)
            table[j] = true;
    }
    for (int i = 0; i < t; i++)
    {
        bool visit[10000] = { false, };
        for (int j = 0; j < 10000; j++)
            visit[j] = table[j];
        cin >> a >> b;
        queue<int> q;
        visit[a] = true;
        q.push(a);
        int answer = 1000000000;
        int cnt = 0;
        int flag = 0;
        while (!q.empty())
        {
            int len = q.size();
            for (int j = 0; j < len; j++)
            {
                int x = q.front();
                q.pop();
                if (x == b)
                {
                    answer = min(answer, cnt);
                    break;
                }
                int digit[4];
                digit[0] = x / 1000;
                x %= 1000;
                digit[1] = x / 100;
                x %= 100;
                digit[2] = x / 10;
                x %= 10;
                digit[3] = x;
                for (int k = 0; k < 4; k++)
                {
                    int t;
                    int num = 0;
                    if (k == 0)
                        num = 1;
                    for (int l = num; l < 10; l++)
                    {
                        if (k == 0)
                            t = l * 1000;
                        else
                            t = digit[0] * 1000;
                        if (k == 1)
                            t += l * 100;
                        else
                            t += digit[1] * 100;
                        if (k == 2)
                            t += l * 10;
                        else
                            t += digit[2] * 10;
                        if (k == 3)
                            t += l;
                        else
                            t += digit[3];
                        if (!visit[t])
                        {
                            visit[t] = true;
                            q.push(t);
                        }
                    }
                }
            }
            if (flag == 1)
                break;
            cnt++;
        }
        if (answer == 1000000000)
            cout << "Impossible\n";
        else
            cout << answer << '\n';
    }
    return (0);
}