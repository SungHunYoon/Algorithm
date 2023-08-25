#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>

using namespace std;

int main(void)
{
    int n;
    vector<string> arr;

    cin >> n;
    arr.assign(n, "");
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<string, int> dict;
    map<string, int>::iterator iter;
    for (int i = 0; i < n; i++)
    {
        iter = dict.find(arr[i]);
        if (iter != dict.end())
            iter->second++;
        else
            dict.insert(make_pair(arr[i], 1));
    }
    string answer = "";
    int cnt = 0;
    for (iter = dict.begin(); iter != dict.end(); iter++)
    {
        if (cnt < iter->second)
        {
            answer = iter->first;
            cnt = iter->second;
        }
        else if (cnt == iter->second && answer > iter->first)
        {
            answer = iter->first;
            cnt = iter->second;
        }
    }
    cout << answer << endl;
    return (0);
}