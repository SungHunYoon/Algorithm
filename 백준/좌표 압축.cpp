#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n;
int arr[1000001];
map<int, int> m;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        map<int, int>::iterator iter;
        iter = m.find(arr[i]);
        if (iter == m.end())
            m.insert({arr[i], 0});
    }
    int cnt = 0;
    for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++)
    {
        iter->second = cnt;
        cnt++;
    }
    for (int i = 0; i < n; i++)
        cout << m[arr[i]] << '\n';
    return (0);
}