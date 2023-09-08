#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int t;
int n;

int inner_distance(string s1, string s2, string s3)
{
    int dis = 0;
    for (int i = 0; i < 4; i++)
    {
        if (s1[i] != s2[i])
            dis++;
        if (s1[i] != s3[i])
            dis++;
        if (s2[i] != s3[i])
            dis++;
    }
    return (dis);
}

int nCr(vector<string> &arr, vector<string> &strs, int index, int rindex, int r, int localn)
{
    if (r == rindex)
        return (inner_distance(strs[0], strs[1], strs[2]));
    else if (localn == index)
        return (0);
    int ret = 0;

    int tmp = 0;
    tmp = nCr(arr, strs, index + 1, rindex, r, localn);
    if (ret == 0 || (tmp != 0 && ret > tmp))
        ret = tmp;
    strs.push_back(arr[index]);
    tmp = nCr(arr, strs, index + 1, rindex + 1, r, localn);
    if (ret == 0 || (tmp != 0 && ret > tmp))
        ret = tmp;
    strs.erase(strs.end());
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
        cin >> n;
        vector<string> arr;
        for (int j = 0; j < n; j++)
        {
            string s;
            cin >> s;
            arr.push_back(s);
        }
        if (n > 32)
            cout << "0\n";
        else
        {
            vector<string> answer;
            cout << nCr(arr, answer, 0, 0, 3, arr.size()) << '\n';
        }
    }
    return (0);
}