#include <iostream>

using namespace std;

int gcd( int a, int b ){
	while( b != 0 ){
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int lcm( int a, int b ){
	return a * b / gcd( a, b );
}

int main()
{
	int T;
	cin >> T;

	for( int i = 0; i < T; i++ )
	{
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		/*
		int temp_x = 1, temp_y = 1;
		int cnt = 1;
		while( 1 )
		{
			if( temp_x == x && temp_y == y )
			{
				cout << cnt << '\n';
				break;
			}
			else if( temp_x == M && temp_y == N )
			{
				cout << -1 << '\n';
				break;
			}

			if( temp_x < M ) temp_x++;
			else temp_x = 1;
			if( temp_y < N ) temp_y++;
			else temp_y = 1;
			cnt++;
		}
		*/

		int temp_x = 1, temp_y = 1;
		int cnt = 1;
		while( 1 )
		{
			if( temp_x == x && temp_y == y )
			{
				cout << cnt << '\n';
				break;
			}
			
			if( lcm( M, N ) < cnt )
			{
				cout << -1 << '\n';
				break;
			}

			if( temp_x == x )
			{
				temp_y += M;
				cnt += M;
				while( temp_y > N )
				{
					temp_y -= N;
					//cnt -= N;
				}
			}
			else
			{
				temp_x++;
				if( temp_x > M ) temp_x = 1;
				temp_y++;
				if( temp_y > N ) temp_y = 1;
				cnt++;
			}
		}
	}

	return 0;
}