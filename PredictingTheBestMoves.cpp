/*Dr. Abagale Xenovian, a reclusive mathematician and master of games, has found a potentially valuable exploit in her favorite video game. When she uses a special attack combination, one of two things happen:

1. If her score is even, she loses 99 points and then her score is multiplied by 3.

2. If her score is odd, she loses 15 points and then her score is multiplied by 2.

Note that all scores are limited to a max value of 1,000,000. Any score that hits that limit will immediately loop back around (so a score of 1,000,007 just becomes a score of 7). Likewise, any score that goes below zero ALSO loops around (so a score of -7 would become a score of 999,993).

Given a starting score ( S ) and a number of times the exploit is used ( k ), determine Dr. Xenovian's final score in the game.

Input Format

The first line is a number ( T ), indicating the number of test cases. The next T lines each have two values, S and k, indicating the starting score and the number of times the exploit is used, respectively.

Constraints

1 ≤ T ≤ 100
0 ≤ S ≤ 1,000,000
0 ≤ k ≤ 100
Output Format

T lines, each indicating the final score in the associated game.
*/

using namespace std;
#include <iostream>

int check_bounds(int num){
  while(num > 1000000 || num < 0)
  {
    if (num > 1000000)
    {
      num = num - 1000000;
    }
    else if (num < 0)
    {
     num = 1000000 + num;
    }
    else
    {
      return num;
    }
  }
  return num;
}

int main()
{
  int test_cases; 
  int S; 
  int k;
  cin >> test_cases;
  int input_arr[test_cases][2];
  
  //Populate the input array with initial scores and exploits
  for(int i = 0; i < test_cases; i++){
    cin >> S;
    cin >> k;
    input_arr[i][0] = S;
    input_arr[i][1] = k;
    
  }
  
  // loop through each test case
  for(int i = 0; i < test_cases; i++)
  {
    // loop through each exploit
    for (int j = 0; j < input_arr[i][1]; j++)
    {
      // if the score is odd
      if (input_arr[i][0] % 2)
      {
        input_arr[i][0] = (input_arr[i][0] - 15) * 2;
      }
      else
      {
        input_arr[i][0] = (input_arr[i][0] - 99) * 3;
      }
      input_arr[i][0] = check_bounds(input_arr[i][0]);
    }
  }
  
  for(int i = 0; i < test_cases; i++){
    cout << input_arr[i][0] << endl;
  }
}
