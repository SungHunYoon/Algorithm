#include <iostream>

using namespace std;

#define NOCOUNT 10000

int min_cnt = NOCOUNT;

int makeOne( int integer, int cnt )
{
	if( integer == 1 ) return cnt;

	cnt++;

	if( integer <= 0 ) return NOCOUNT;
	else if( min_cnt <= cnt ) return NOCOUNT;

	int temp = 0;

	if( integer % 3 == 0 )
	{
		temp = makeOne( integer / 3, cnt );
		if( min_cnt > temp )
		{
			min_cnt = temp;
		}
	}
	if( integer % 2 == 0 )
	{
		temp = makeOne( integer / 2, cnt );
		if( min_cnt > temp )
		{
			min_cnt = temp;
		}
	}

	temp = makeOne( integer - 1, cnt );
	if( min_cnt > temp )
	{
		min_cnt = temp;
	}

	return min_cnt;
}

int main()
{
	int n;
	cin >> n;

	cout << makeOne( n, 0 ) << endl;

	return 0;
}