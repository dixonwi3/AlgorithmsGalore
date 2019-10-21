/*
Description
Queen Mellifluous has positioned her primary hive securely in a mountain pass, surrounded by N evenly-spaced outposts, all in a line. She has positioned K guards in a subset of those outposts, but is still concerned about an infiltrator sneaking in. Given a set of guard positions, can you identify the distance of the outpost furthest from the nearest guard?

Input Format

The first line has two values: N (the number of outposts, labeled 0 through N-1) and K (the number of guards on duty). The next K values indicate the outpost numbers where each guard is patrolling. For example, if there are 100 outposts and three guards at outposts 10, 60, 95, then an infiltrator coming in at the outpost 35 would be 25 outposts away from the nearest guard.

Constraints

1 ≤ k ≤ 109
1 ≤ N ≤ 105
0 ≤ guard positions ≤ k
Output Format

Output a single number indicating the farthest an infiltrator can be to the nearest guarded outpost as they try to sneak in.
*/

#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
  int num_posts = 0;
  int num_guards = 0;
  int guard_pos;
  int dist;
  vector<int> dist_posts;
  vector<int> guards;
  cin >> num_posts;
  cin >> num_guards;
  for (int i = 0; i < num_guards; i++)
  {
    cin >> guard_pos;
    guards.push_back(guard_pos);
  }
  for (int m = 0; m < num_posts; m++)
  {
    dist = INT_MAX;
    for (int n = 0; n < num_guards; n++)
    {
      if ((abs(guards[n] - m)) < dist)
      {
        dist = abs(guards[n] - m);
      }
    }
    dist_posts.push_back(dist);
  }
  int max_post = 0;
  for (int k = 0; k < num_posts; k++)
  {
    if (dist_posts[k] > dist_posts[max_post])
    {
      max_post = k;
    }
  }
  cout << dist_posts[max_post] << endl;
}
