/*
Description
Dr. Xenovian has many ideas for designing new board games. After she tries a set of new games, she also comes up with ways of merging those games to explore more possibilities. How many total new games can she make?

During each brainstorming session, Dr. Xenovian starts with n different ideas. She groups these into sets of m ideas to design each game. After that, for every c games she designs and plays, she can combine those games into yet one more game.

For example, assume she starts with n=4 ideas, plans to use only one new idea for each game (m = 1), and for every two games she plays, she will generate ideas for one new game idea (c = 2). Dr. Xenovian can design 4 games with her initial ideas, and then (after playing those games) comes up with 2 new games. When those new games finish, she can use them to generate yet another 1 game, for a grand total of 7 games ever.

Input Format

The first line contains a single integer T indicating the number of test cases.

The next T lines each have three integers, separated by spaces, indicating n, m, and c for that test case.

Constraints

1 ≤ T ≤ 1000
2 ≤ n ≤ 105
1 ≤ m ≤ n
2 ≤ c ≤ n
Output Format

For each test case, print the number of games that can be created during that brainstorming session.
*/
using namespace std;
#include <iostream>
int initIdeas(int n, int m){
  return n/m;
}
int addIdeas(int new_ideas, int c){
  if (new_ideas == 0){
    return 0;
  }
  int new_games = (new_ideas / c); // = 1
  int r = new_ideas % c; // = 1
  int soln = new_games + r;
  return new_games + addIdeas(soln, c);
}
int main(){
  int n;
  int m;
  int c;
  int test_cases;
  int rem;
  int game_pool;
  int new_games;
  int nested_rem;
  cin >> test_cases;

  for (int i = 0; i < test_cases; i++){ 
    cin >> n;
    cin >> m;
    cin >> c;
    int soln = n/m; // = 3
    rem = n % m; // = 0
    game_pool = soln; // = 3
    while(game_pool >= c){
      new_games = game_pool / c; // = 1, 1
      nested_rem = game_pool % c; // = 1, 0
      soln += new_games; // 4
      game_pool = new_games + nested_rem; // 2
    }
    cout << soln << "\n";
  }
}
