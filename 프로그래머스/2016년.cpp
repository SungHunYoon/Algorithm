#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    vector<string> day = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
	vector<int> month = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int cnt = 0;

	for( int i = 0; i < a - 1; i++ )
	{
		cnt += month[ i ];
	}

	cnt += b - 1;

	answer = day[ cnt % 7 ];
    
    return answer;
}