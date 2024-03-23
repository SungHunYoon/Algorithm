#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

int A, B, C;
queue<tuple<int, int, int>> q;
bool visit[201][201][201];
set<int> answer;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> A >> B >> C;
	q.push({0, 0, C});
	answer.insert(C);
	visit[0][0][C] = true;
	while (!q.empty())
	{
		auto t = q.front();
		q.pop();

		int a, b, c;

		a = get<0>(t);
		b = get<1>(t);
		c = get<2>(t);
		if (a < A && c != 0)
		{
			if (a <= c && c - (A - a) >= 0)
			{
				c = c - (A - a);
				a = A;
			}
			else
			{
				if (a + c <= A)
				{
					a = a + c;
					c = 0;
				}
				else
				{
					c = a + c - A;
					a = A;
				}
			}
			//cout << "test1 : " << a << " " << b << " " << c << '\n';
			if (!visit[a][b][c])
			{
				visit[a][b][c] = true;
				q.push({a, b, c});
				if (a == 0)
					answer.insert(c);
			}
		}
		a = get<0>(t);
		b = get<1>(t);
		c = get<2>(t);
		if (a < A && b != 0)
		{
			if (a <= b && b - (A - a) >= 0)
			{
				b = b - (A - a);
				a = A;
			}
			else
			{
				if (a + b <= A)
				{
					a = a + b;
					b = 0;
				}
				else
				{
					b = a + b - A;
					a = A;
				}
			}
			//cout << "test2 : " << a << " " << b << " " << c << '\n';
			if (!visit[a][b][c])
			{
				visit[a][b][c] = true;
				q.push({a, b, c});
				if (a == 0)
					answer.insert(c);
			}
		}
		a = get<0>(t);
		b = get<1>(t);
		c = get<2>(t);
		if (b < B && c != 0)
		{
			if (b <= c && c - (B - b) >= 0)
			{
				c = c - (B - b);
				b = B;
			}
			else
			{
				if (b + c <= B)
				{
					b = b + c;
					c = 0;
				}
				else
				{
					c = b + c - B;
					b = B;
				}
			}
			//cout << "test3 : " << a << " " << b << " " << c << '\n';
			if (!visit[a][b][c])
			{
				visit[a][b][c] = true;
				q.push({a, b, c});
				if (a == 0)
					answer.insert(c);
			}
		}
		a = get<0>(t);
		b = get<1>(t);
		c = get<2>(t);
		if (b < B && a != 0)
		{
			if (b <= a && a - (B - b) >= 0)
			{
				a = a - (B - b);
				b = B;
			}
			else
			{
				if (b + a <= B)
				{
					b = b + a;
					a = 0;
				}
				else
				{
					a = b + a - B;
					b = B;
				}
			}
			//cout << "test4 : " << a << " " << b << " " << c << '\n';
			if (!visit[a][b][c])
			{
				visit[a][b][c] = true;
				q.push({a, b, c});
				if (a == 0)
					answer.insert(c);
			}
		}
		a = get<0>(t);
		b = get<1>(t);
		c = get<2>(t);
		if (c < C && a != 0)
		{
			if (c <= a && a - (C - c) >= 0)
			{
				a = a - (C - c);
				c = C;
			}
			else
			{
				if (c + a <= C)
				{
					c = c + a;
					a = 0;
				}
				else
				{
					a = c + a - C;
					c = C;
				}
			}
			//cout << "test5 : " << a << " " << b << " " << c << '\n';
			if (!visit[a][b][c])
			{
				visit[a][b][c] = true;
				q.push({a, b, c});
				if (a == 0)
					answer.insert(c);
			}
		}
		a = get<0>(t);
		b = get<1>(t);
		c = get<2>(t);
		if (c < C && b != 0)
		{
			if (c <= b && b - (C - c) >= 0)
			{
				b = b - (C - c);
				c = C;
			}
			else
			{
				if (c + b <= C)
				{
					c = c + b;
					b = 0;
				}
				else
				{
					b = c + b - C;
					c = C;
				}
			}
			//cout << "test6 : " << a << " " << b << " " << c << '\n';
			if (!visit[a][b][c])
			{
				visit[a][b][c] = true;
				q.push({a, b, c});
				if (a == 0)
					answer.insert(c);
			}
		}
	}
	for (auto it = answer.begin(); it != answer.end(); it++)
		cout << *it << ' ';
	cout << '\n';
	return 0;
}