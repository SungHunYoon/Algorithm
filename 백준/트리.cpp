#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int recursive(vector<int> *arr, int *v, int ref, int index)
{
    int ret = 1;
    for (int i = 0; i < arr[index].size(); i++)
    {
        if (!v[arr[index][i]])
        {
            v[arr[index][i]] = ref;
            ret = recursive(arr, v, ref, arr[index][i]);
        }
    }
    return (ret);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t = 0;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;

        vector<int> arr[501];
        int v[501] = { 0, };
        int E[501] = { 0, };

        for (int i = 0; i < m; i++)
        {
            int s, e;
            cin >> s >> e;
            arr[s].push_back(e);
            arr[e].push_back(s);
            E[s]++;
        }
        int answer = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!v[i])
            {
                v[i] = i;
                recursive(arr, v, i, i);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int eSize = 0;
            for (int j = 1; j <= n; j++)
            {
                if (v[j] == i)
                    eSize += E[j];
            }
            if (eSize + 1 == count(v + 1, v + n + 1, i))
                answer++;
        }
        cout << "Case " << t + 1 << ": ";
        if (answer == 0)
            cout << "No trees.\n";
        else if (answer == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << answer << " trees.\n";
        t++;
    }
    return (0);
}