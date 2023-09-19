#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, t, g;
bool visit[100000];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> t >> g;
    queue<int> q;
    visit[n] = true;
    q.push(n);
    int cnt = 0;
    int flag = 0;
    int answer = 1000000000;
    while (!q.empty())
    {
        int len = q.size();
        for (int i = 0; i < len; i++)
        {
            int x = q.front();
            q.pop();
            if (x == g)
            {
                answer = min(answer, cnt);
                flag = 1;
                break;
            }
            int dx = x + 1;
            if (dx < 100000 && !visit[dx])
            {
                visit[dx] = true;
                q.push(dx);
            }
            dx = x * 2;
            int digit[5];
            digit[0] = dx / 10000;
            dx %= 10000;
            digit[1] = dx / 1000;
            dx %= 1000;
            digit[2] = dx / 100;
            dx %= 100;
            digit[3] = dx / 10;
            dx %= 10;
            digit[4] = dx;
            if (digit[0] != 0)
                digit[0]--;
            else if (digit[1] != 0)
                digit[1]--;
            else if (digit[2] != 0)
                digit[2]--;
            else if (digit[3] != 0)
                digit[3]--;
            else if (digit[4] != 0)
                digit[4]--;
            dx = digit[0] * 10000;
            dx += digit[1] * 1000;
            dx += digit[2] * 100;
            dx += digit[3] * 10;
            dx += digit[4];
            if (dx < 100000 && !visit[dx])
            {
                visit[dx] = true;
                q.push(dx);
            }
        }
        cnt++;
        if (cnt > t || flag == 1)
            break;
    }
    if (answer == 1000000000)
        cout << "ANG\n";
    else
        cout << answer << '\n';
    return (0);
}