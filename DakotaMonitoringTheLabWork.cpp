/*
Description
Dakota Smith keeps finding new and interesting artifacts, each of which she sends off to ATOM labs for analysis. As ATOM finishes analyzing the artifacts, it sends them back to her.

Strangely, ATOM works on a Last-In-First-Out system, so Dakota either gets results back about an artifact immediately, or else she needs to wait a while to hear anything. As such, she always wants to know what the most valuable artifact she is waiting for is.

Input Format

The first line is an integer N, indicating the number of interactions Dakota will have with ATOM labs. The next N lines contain a number and possibly an item value (x) in the format:

1 x - Send an artifact of value x to the lab.
2   - Receive the most recent artifact back from the lab.
3   - Print the value of the most valuable item still at the lab.
Constraints

1 ≤ N ≤ 105
1 ≤ x ≤ 109
Output Format

 For each type 3 action, print the value of the most valuable artifact still in the lab, on a new line.
*/

#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;
int main()
{
  int N;
  int op;
  int num;
  vector<int> stack;
  cin >> N;
  for (int i = 0 ; i < N; i++)
  {
    cin >> op;
    if (op == 1)
    {
      cin >> num;
      stack.push_back(num);
    }
    if (op == 2)
    {
      stack.pop_back();
    }
    if (op == 3)
    {
      int maxi = INT_MIN;
      for (int j = 0; j < stack.size(); j++)
      {
        if(stack[j] > maxi)
        {
          maxi = stack[j];
        }
      }
      cout << maxi << endl;
    }
    
  }
}
