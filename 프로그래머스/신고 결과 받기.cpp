#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>

using namespace std;

vector<string> split( string input, char delimiter ) {
	vector<string> answer;
	stringstream ss( input );
	string temp;

	while( getline( ss, temp, delimiter ) ) {
		answer.push_back( temp );
	}

	return answer;
}

vector<int> solution( vector<string> id_list, vector<string> report, int k ) {
	vector<int> answer;

	map<string, int> report_list;
	map<string, set<string>> return_mail;

	for( int i = 0; i < id_list.size(); i++ )
	{
		report_list[ id_list[ i ] ] = 0;
	}

	for( int i = 0; i < report.size(); i++ )
	{
		vector<string> name;

		name = split( report[ i ], ' ' );

		return_mail[ name[ 1 ] ].insert( name[ 0 ] );
	}

	for( map<string, set<string>>::iterator it = return_mail.begin(); it != return_mail.end(); ++it )
	{
		if( it->second.size() >= k )
		{
			for( set<string>::iterator iter = it->second.begin(); iter != it->second.end(); ++iter )
			{
				report_list[ *iter ] += 1;
			}
		}
	}

	for( int i = 0; i < id_list.size(); i++ )
	{
		answer.push_back( report_list[ id_list[ i ] ] );
	}

	return answer;
}