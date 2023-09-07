#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int t;
int A;
int B;

int Double(int n)
{
    int ret;
    ret = n * 2 % 10000;
    return (ret);
}

int Sub(int n)
{
    int ret;
    ret = n - 1;
    if (ret < 0)
        ret = 9999;
    return (ret);
}

int Left(int n)
{
    int d1, d2, d3, d4;
    int ret;

    d1 = n / 1000;
    n %= 1000;
    d2 = n / 100;
    n %= 100;
    d3 = n / 10;
    n %= 10;
    d4 = n / 1;

    ret = d2 * 1000;
    ret += d3 * 100;
    ret += d4 * 10;
    ret += d1 * 1;
    return (ret);
}

int Right(int n)
{
    int d1, d2, d3, d4;
    int ret;

    d1 = n / 1000;
    n %= 1000;
    d2 = n / 100;
    n %= 100;
    d3 = n / 10;
    n %= 10;
    d4 = n / 1;

    ret = d4 * 1000;
    ret += d1 * 100;
    ret += d2 * 10;
    ret += d3 * 1;
    return (ret);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> A >> B;

        queue<int> q;
        bool visit[10001] = { false, };
        pair<char, int> d[10001] = { {0, 0}, };

        d[A].second = -1;
        visit[A] = true;
        q.push(A);
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            if (x == B)
                break;
            int c1, c2, c3, c4;
            c1 = Double(x);
            if (!visit[c1])
            {
                visit[c1] = true;
                d[c1].first = 'D';
                d[c1].second = x;
                q.push(c1);
            }
            c2 = Sub(x);
            if (!visit[c2])
            {
                visit[c2] = true;
                d[c2].first = 'S';
                d[c2].second = x;
                q.push(c2);
            }
            c3 = Left(x);
            if (!visit[c3])
            {
                visit[c3] = true;
                d[c3].first = 'L';
                d[c3].second = x;
                q.push(c3);
            }
            c4 = Right(x);
            if (!visit[c4])
            {
                visit[c4] = true;
                d[c4].first = 'R';
                d[c4].second = x;
                q.push(c4);
            }
        }
        vector<char> answer;
        while (d[B].second != -1)
        {
            //cout << d[B].first;
            answer.push_back(d[B].first);
            B = d[B].second;
        }
        for (int i = answer.size() - 1; i >= 0; i--)
            cout << answer[i];
        cout << '\n';
    }
    return (0);
}