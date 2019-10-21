/*
Description
In looking through her previously-sorted files, Dakota has realized that they are out of order. Fortunately the sabatour made only a quick change to each set of files, either turning around a whole segment of them (so that they are in the reverse order of what is expected) or by swapping two entires. Can you find a single reverse or swap operation that will restore her files to sorted order?

Input Format

The file line contains a value N, indicating how many files there are in this set.

The next N values (on the next line) indicate the IDs of each file.

Constraints

2 ≤ N ≤ 105
0 ≤ file id ≤ 106
Output Format

If the array is already sorted OR Dakota can fix it with a single "swap" or "reverse" operation, write "yes" on the first line. Otherwise write "no" on the first line.

If a single operation needs to be performed, begin the second line with "swap" or "reverse" indicating either the two file positions to swap -or- the first and last positions that need to all be reversed. (if both are possible provide the "swap" option)

NOTE: You should assume the first position is 1 for the purposes of this question.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int checkReversibility(vector<int> list, int index_start)
{
  int end_index;
  for (int i = index_start + 1; i < list.size(); i++)
  {
    if (list[i] < list[i - 1])
    {
      end_index = i;
    }
    else
    {
      break;
    }
  }
  reverse(list.begin() + index_start, list.begin() + end_index + 1);
  if (is_sorted(list.begin(), list.end()))
  {
    return end_index + 1;
  }
  else
  {
    return -1;
  }
}

int checkSwap(vector<int> list, int start)
{
  int end_index = -1;
  for (int i = start + 2; i < list.size(); i++)
  {
    if((list[i] >= list[start - 1] && list[i] <= list[start + 1]))
    {
      end_index = i;
      swap(list[start], list[i]);
      break;
    }
  }

  if (is_sorted(list.begin(), list.end()))
  {
    return end_index;
  }
  else
  {
    return -1;
  }
}

int main()
{
  int num_items;
  int num;
  vector<int> list;
  cin >> num_items;
  if (num_items)
  for(int i = 1; i <= num_items; i++)
  {
    cin >> num;
    list.push_back(num);
  }
  
  if(num_items == 2 && (!is_sorted(list.begin(), list.end())))
  {
    cout << "yes" << endl;
    cout << "swap 1 2" <<  endl;
    return 0;
  }
  int start_swap = -1;
  int end_swap = -1;
  // check swapability
  for (int i = 1; i < num_items; i++)
  {
    if (list[i] < list[i-1])
    {
      start_swap = i-1;
      end_swap = checkSwap(list, i-1);
      break;
    }
  }
  if (end_swap >= 0)
  {
    cout << "yes" << endl;
    cout << "swap " << start_swap + 1 << " " << end_swap + 1<< endl;
    return 0;
  }

  int end_index = -1;
  int start_index = -1;
  
  // check reversibility
  for (int j = 1; j < num_items; j++)
  {
    if (list[j] < list[j-1])
    {
      start_index = j;
      end_index = checkReversibility(list, j-1);
      break;
    }
  }
  if (end_index >= 0)
  {
    cout << "yes" << endl;
    cout << "reverse "<< start_index << " " << end_index << endl;
    return 0;
  }
  cout << "no" << endl;
}
