/*
* C++ implementation of QuickSort and Insertion Sort timed
* Implementation of QuickSort found on: https://www.geeksforgeeks.org/insertion-sort/
* Implementation of Insertion Sort found on: https://www.geeksforgeeks.org/insertion-sort-using-c-stl/
*
*/
#include <stdio.h> 
#include <ctime>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>


using namespace std;


const int NUM_ITEMS = 150;

const int NUM_ITER = 1000;

// A utility function to swap two elements 
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}


// Driver program to test above functions 
int main()
{

	int arr[NUM_ITEMS];
	int n = sizeof(arr) / sizeof(arr[0]);
	int data_arr[NUM_ITEMS];

	std::clock_t tot_time_qs = 0;
	std::clock_t tot_time_is = 0;

	for (int j = 0; j < NUM_ITER; j++)
	{
		// random seed each iteration
		srand(j);

		// populate data array with random data
		for (size_t i = 0; i < NUM_ITEMS; i++)
		{
			data_arr[i] = (rand());
		}

		for (size_t i = 0; i < NUM_ITEMS; i++)
		{
			arr[i] = data_arr[i];
		}

		// get insertion sort time
		std::clock_t start_time_is = std::clock();
		insertionSort(arr, n);
		tot_time_is += std::clock() - start_time_is;

		for (size_t i = 0; i < NUM_ITEMS; i++)
		{
			arr[i] = data_arr[i];
		}

		// get quicksort time
		std::clock_t start_time = std::clock();
		quickSort(arr, 0, n - 1);
		tot_time_qs += std::clock() - start_time;

	}

	cout << endl;

	printf("For %d items: \n", NUM_ITEMS);
	printf("Quicksort Time:      %.8f seconds \n", ((((double)tot_time_qs) / (double)CLOCKS_PER_SEC) / double(NUM_ITER)));
	printf("Insertion Sort Time: %.8f seconds\n",  ((((double)tot_time_is) / (double)CLOCKS_PER_SEC) / double(NUM_ITER)));
	return 0;
}
