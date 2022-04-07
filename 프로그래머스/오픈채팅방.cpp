#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

#pragma warning(disable : 4996)

using namespace std;

typedef struct
{
	string user_id;
	string state;
	string nickname;
}user_t;

typedef struct  
{
	string user_id;
	string nickname;
}user_list_t;

vector<string> split( string input, char delimiter ) {
	vector<string> answer;
	stringstream ss( input );
	string temp;

	while( getline( ss, temp, delimiter ) ) {
		answer.push_back( temp );
		//cout << temp << endl;
	}

	return answer;
}

vector<string> solution( vector<string> record )
{
	vector<user_t> user;
	map<string, string> user_list;

	for( int i = 0; i < record.size(); i++ )
	{
		vector<string> str = split( record[i], ' ' );
		
		user_t u;

		u.state = str[ 0 ];
		u.user_id = str[ 1 ];
		
		if( str.size() > 2 )
		{
			u.nickname = str[ 2 ];
		}

		user.push_back( u );

		if( u.state == "Enter" || u.state == "Change" )
		{
			user_list[ u.user_id ] = u.nickname;
		}
	}

	vector<string> answer;

	for( int i = 0; i < user.size(); i++ )
	{
		string str;

		if( user[ i ].state == "Enter" )
		{
			str = user_list[ user[ i ].user_id ] + "님이 들어왔습니다.";
			answer.push_back( str );
		}
		else if( user[ i ].state == "Leave" )
		{
			str = user_list[ user[i].user_id ] + "님이 나갔습니다.";
			answer.push_back( str );
		}
	}

	return answer;
}