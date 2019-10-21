/*
Description
There are many types and sizes of smart bricks; all of them will automatically link together when touching. Given N types of bricks where each brick i has length Li , how many ways are there to lay them in a line with total length Ltotal ?

Input Format

The first line of the input provides T, the total number of test cases.
The next T pairs of lines describe a single test case:
The first line in a test case privides the number of brick types (N) and the total target length ( Ltotal ).
The second line has N values, each indicating the length of each available brick.
Constraints

1 ≤ T ≤ 10
1 ≤ N ≤ 50
1 ≤ Ltotal ≤ 106
1 ≤ Li ≤ 106
Output Format

T lines, one per test case, each indicating the number of combinations possible to make a line of that total length. Some of the values are quite large, so mod your answer by 1000000009.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int tests;
	cin >> tests;
	for (int i = 0; i < tests; i++)
	{
		int numBricks; int target; int b; vector<int> bricks;
		cin >> numBricks >> target;
		for (int m = 0; m < numBricks; m++)
		{
			cin >> b;
			bricks.push_back(b);
		}
		long long* sln = new long long[target + 1];
		sln[0] = 0;
		sort(bricks.begin(), bricks.end());
		
	    for (int k = 1; k < target + 1; k++)
	    {
	    	int j = 0;
	    	int c = count(bricks.begin(), bricks.end(), k);
	    	sln[k] = c;
	    	while(bricks[j] < k && bricks[j]!=0)
	    	{
	    		sln[k] += sln[k - bricks[j]];
	    		sln[k] = sln[k] % 1000000009;
	    		++j;
	    	}
	    }
	    cout << sln[target] % 1000000009 << endl;
	}
}
