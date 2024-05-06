#include <iostream>
#include <algorithm>

using namespace std;

string S, P;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S >> P;
    string A;
    int answer = 0;
    for (int i = 0; i < P.size(); i++)
    {
        string T;
        T.append(1, P[i]);
        while (S.find(T) != string::npos)
        {
            if (i < P.size())
                i++;
            else
                break;
            T.append(1, P[i]);
        }
        i--;
        answer++;
    }
    cout << answer << '\n';
    return 0;
}