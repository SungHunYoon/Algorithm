#include <iostream>
#include <vector>
#include <string>

using namespace std;

int isValid(string pos)
{
    if (!('A' <= pos[0] && pos[0] <= 'H'))
        return (0);
    if (!('1' <= pos[1] && pos[1] <= '8'))
        return (0);
    return (1);
}

string move(string pos, string m)
{
    for (int i = 0; i < m.length(); i++)
    {
        if (m[i] == 'R')
            pos[0] += 1;
        else if (m[i] == 'L')
            pos[0] -= 1;
        else if (m[i] == 'B')
            pos[1] -= 1;
        else if (m[i] == 'T')
            pos[1] += 1;
    }
    return (pos);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string king;
    string stone;
    int n;
    vector<string> arr;
    
    cin >> king >> stone >> n;
    arr.assign(n, "");
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        string tmp = move(king, arr[i]);
        
        if (isValid(tmp) == 1)
        {
            if (stone == tmp)
            {
                string tmp1 = move(stone, arr[i]);
                if (isValid(tmp1) == 1)
                    stone = tmp1;
                else
                    continue ;
            }
            king = tmp;
        }
    }
    cout << king << '\n' << stone << '\n';
    return (0);
}