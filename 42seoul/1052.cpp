#include <iostream>
#include <vector>

using namespace std;

int N, K;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> K;
    if (N <= K)
    {
        cout << "0\n";
        return 0;
    }
    long long tmp;
    for (int i = 0; i < K; i++)
    {
        tmp = 1;
        while ((N + 1) / 2 > tmp)
            tmp *= 2;
        N -= tmp;
        if (K - (i + 1) >= N)
        {
            cout << "0\n";
            return 0;
        }
    }
    cout << tmp - N << '\n';
	return 0;
}
