#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find(vector<string> strs, int n)
{
    int size = strs[0].size();
    int index = 1;

    for (int i = size - index; i >= 0; i--)
    {
        int flag = 1;
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                string str1 = strs[j].substr(i);
                string str2 = strs[k].substr(i);
                
                if (str1 == str2)
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
                break;
        }
        if (flag == 1)
            return (index);
        index++;
    }
    return (index);
}

int main(void)
{
    int n;
    vector<string> strs;

    cin >> n;
    strs.assign(n, "");
    for (int i = 0; i < n; i++)
        cin >> strs[i];
    cout << find(strs, n) << endl;
    return (0);
}