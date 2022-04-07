#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution( vector<string> participant, vector<string> completion ) {
	string answer = "";
    /*
	vector<bool> a( participant.size() );
	vector<bool> b( completion.size() );

	for( int i = 0; i < participant.size(); i++ )
	{
		for( int j = 0; j < completion.size(); j++ )
		{
            if( b[ j ] ) continue;
			if( completion[ j ] == participant[ i ] )
			{
				if( !a[ i ] && !b[ j ] )
				{
					a[ i ] = true;
					b[ j ] = true;
					break;
				}
			}
		}
	}

	for( int i = 0; i < a.size(); i++ )
	{
		if( !a[ i ] )
		{
			answer = participant[ i ];
			break;
		}
	}
    */
    // 효율성 Fail.. O(1) 의 복잡도를 가진 unordered_map 사용이나
    // 정렬 후 없는 값을 리턴하는 형식을 활용해야 함.
    unordered_map<string, int> participants;

	for( string name : participant )
	{
		++participants[ name ];
	}

	for( string name : completion )
	{
		--participants[ name ];
	}

	for( auto pair : participants )
	{
		if( pair.second > 0 )
		{
			answer = pair.first;
		}
	}
    
	return answer;
}