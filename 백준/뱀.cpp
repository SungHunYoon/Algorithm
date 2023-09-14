#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, l;
int apple[101][101];
char dir[10001];
pair<int, int> head;
pair<int, int> tail;
pair<int, int> snake[101][101];

int dir_change(int d, char change)
{
    if (change == 'L')
    {
        if (d == 1)
            d = 4;
        else if (d == 2)
            d = 3;
        else if (d == 3)
            d = 1;
        else
            d = 2;
    }
    else if (change == 'D')
    {
        if (d == 1)
            d = 3;
        else if (d == 2)
            d = 4;
        else if (d == 3)
            d = 2;
        else
            d = 1;
    }
    return (d);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        apple[r][c] = 1;
    }

    cin >> l;
    for (int i = 0; i < l; i++)
    {
        int x;
        char c;
        cin >> x >> c;
        dir[x] = c;
    }

    head = {1, 1};
    tail = {1, 1};
    snake[1][1] = head;
    int d = 1;
    int i;
    for (i = 1; i < 10001; i++)
    {
        pair<int, int> tmp;
        if (d == 1)
        {
            if (head.first + 1 > n || (snake[head.second][head.first + 1].first != 0 && snake[head.second][head.first + 1].second != 0))
                break;
            tmp = head;
            head.first++;
        }
        else if (d == 2)
        {
            if (head.first - 1 < 1 || (snake[head.second][head.first - 1].first != 0 && snake[head.second][head.first - 1].second != 0))
                break;
            tmp = head;
            head.first--;
        }
        else if (d == 3)
        {
            if (head.second + 1 > n || (snake[head.second + 1][head.first].first != 0 && snake[head.second + 1][head.first].second != 0))
                break;
            tmp = head;
            head.second++;
        }
        else
        {
            if (head.second - 1 < 1 || (snake[head.second - 1][head.first].first != 0 && snake[head.second - 1][head.first].second != 0))
                break;
            tmp = head;
            head.second--;
        }
        snake[tmp.second][tmp.first] = head;
        if (apple[head.second][head.first] == 1)
            apple[head.second][head.first] = 0;
        else
        {
            tmp = tail;
            tail = snake[tail.second][tail.first];
            snake[tmp.second][tmp.first] = {0, 0};
        }
        d = dir_change(d, dir[i]);
    }
    cout << i << '\n';
    return (0);
}