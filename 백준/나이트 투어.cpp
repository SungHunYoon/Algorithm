#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void place(vector<vector<bool>> &table, string str)
{
    int x = str[0] - 'A';
    int y = str[1] - '1';
    
    table[y][x] = true;
}

int isValid(string cur, string next)
{
    int cur_x = cur[0] - 'A';
    int cur_y = cur[1] - '1';
    int next_x = next[0] - 'A';
    int next_y = next[1] - '1';
    int diff_x = cur_x - next_x;
    int diff_y = cur_y - next_y;

    if (abs(diff_x) == 2 && abs(diff_y) == 1)
        return (1);
    else if (abs(diff_x) == 1 && abs(diff_y) == 2)
        return (1);
    else
        return (0);
}

int isValid(string cur, string next, vector<vector<bool>> &table)
{
    int next_x = next[0] - 'A';
    int next_y = next[1] - '1';

    if (table[next_y][next_x])
        return (0);

    return (isValid(cur, next));
}

int main(void)
{
    vector<string> arr;

    arr.assign(36, "");
    for (int i = 0; i < 36; i++)
        cin >> arr[i];
    
    string answer = "Valid";
    vector<vector<bool>> table (6, vector<bool>(6, 0));
    string cur = "";
    for (int i = 0; i < 36; i++)
    {
        if (i == 0)
        {
            cur = arr[i];
            place(table, arr[i]);
        }
        else
        {
            if (isValid(cur, arr[i], table) == 1)
            {
                place(table, arr[i]);
                cur = arr[i];
            }
            else
            {
                answer = "Invalid";
                break;
            }
        }
    }
    if (isValid(cur, arr[0]) == 0)
        answer = "Invalid";
    cout << answer << endl;
    return (0);
}