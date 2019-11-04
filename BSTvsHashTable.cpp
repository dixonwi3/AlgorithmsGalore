#include <iostream>
#include <set>
#include <unordered_set>
#include <ctime>

using namespace std;

const int N = 500000;
const int NUM_ITERS = 1;


int main()
{
	std::multiset<int> bst;
	std::unordered_multiset<int> hash;
	clock_t time_tot_bst = 0;
	clock_t time_tot_hash = 0;
	int i;
	int num_items = N;
  srand(time(0));

	for (int j = 0; j < NUM_ITERS; j++)
	{
    bst.clear();
    hash.clear();
		for (i = 0; i < N; i++)
		{
			// get insertion time up to 3 seconds for bst
			std::clock_t start_time_bst = std::clock();
			int r = rand();
			bst.insert(r);
			time_tot_bst += clock() - start_time_bst;
      /*
			if ((double)time_tot_bst / (double)CLOCKS_PER_SEC > 3)
			{
				num_items = i;
				break;
			}
      */

			// get insertion time for number of items inserted into hash table
			std::clock_t start_time_hash = std::clock();
			hash.insert(r);
			time_tot_hash += clock() - start_time_hash;
      /*
			if ((double)time_tot_hash / (double)CLOCKS_PER_SEC > 3)
			{
				num_items = i;
				break;
			}
      */
		}
	}
	
	printf("For %d items: \n", num_items);
	printf("BST Time:        %.8f seconds \n", (((((double) time_tot_bst) / (double)CLOCKS_PER_SEC)) / (double)NUM_ITERS));
	printf("Hash Table Time: %.8f seconds \n", (((((double)time_tot_hash) / (double)CLOCKS_PER_SEC)) / (double)NUM_ITERS));
}
