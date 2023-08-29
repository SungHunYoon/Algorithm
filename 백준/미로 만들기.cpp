#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    string str;
    cin >> str;

    vector<pair<int, int>> move;
    move.push_back({0, 0});
    int dir = 0; // 0 : S, 1 : E, 2 : N, 3 : W
    int x = 0, y = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'F')
        {
            if (dir == 0)
                y++;
            else if (dir == 1)
                x++;
            else if (dir == 2)
                y--;
            else
                x--;
            move.push_back({x, y});
        }
        else if (str[i] == 'L')
        {
            dir++;
            if (dir > 3)
                dir = 0;
        }
        else
        {
            dir--;
            if (dir < 0)
                dir = 3;
        }
    }
    int min_x = 50, max_x = -50;
    int min_y = 50, max_y = -50;
    for (int i = 0; i < move.size(); i++)
    {
        if (move[i].first < min_x)
            min_x = move[i].first;
        if (move[i].first > max_x)
            max_x = move[i].first;
        if (move[i].second < min_y)
            min_y = move[i].second;
        if (move[i].second > max_y)
            max_y = move[i].second;
    }
    vector<vector<char>> m (max_y - min_y + 1, vector<char>(max_x - min_x + 1, '#'));
    for (int i = 0; i < move.size(); i++)
        m[move[i].second - min_y][move[i].first - min_x] = '.';
    for (int i = 0; i < m.size(); i++)
    {
        for (int j = 0; j < m[i].size(); j++)
            cout << m[i][j];
        cout << '\n';
    }
    return (0);
}