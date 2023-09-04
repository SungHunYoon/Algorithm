#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, b;
    cin >> n >> m >> b;
    map<int, int> dict;
    for (int i = 0; i < n * m; i++)
    {
        int h;
        cin >> h;
        map<int, int>::iterator iter;
        iter = dict.find(h);
        if (iter != dict.end())
            iter->second++;
        else
            dict.insert({h, 1});
    }
    int time = -1;
    int h;
    for (int i = 0; i < 256; i++)
    {
        int tmp = 0;
        int block = b;
        for (map<int, int>::iterator iter = dict.begin(); iter != dict.end(); iter++)
        {
            if (i > iter->first)
            {
                tmp += (i - iter->first) * iter->second;
                block -= (i - iter->first) * iter->second;
            }
            else if (i < iter->first)
            {
                tmp += (iter->first - i) * (iter->second * 2);
                block += (iter->first - i) * iter->second;
            }
        }
        if (block >= 0 && (time == -1 || time > tmp))
        {
            time = tmp;
            h = i;
        }
    }
    cout << time << ' ' << h << '\n';
    return (0);
}