#include <iostream>
#include <string>

using namespace std;

string S, T;
int N;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char c; cin >> c;
        S.append(1, c);
    }
    while (!S.empty())
    {
        int F = 0, B = S.size() -1;
        while (F != B)
        {
            if (S[F] == S[B])
            {
                F++; B--;
            }
            if (S[F] > S[B])
            {
                T.append(1, S.back());
                S.pop_back();
                break;
            }
            else if (S[F] < S[B])
            {
                T.append(1, S.front());
                S.erase(S.begin());
                break;
            }
        }
        if (F == B)
        {
            T.append(1, S.back());
            S.pop_back();
        }
        if (T.size() == 80)
        {
            cout << T << '\n';
            T.clear();
        }
    }
    if (!T.empty())
        cout << T << '\n';
    return 0;
}