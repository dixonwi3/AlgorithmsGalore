/*
Description
Dr. Malcolm Niacal has simplified people down to their basic traits: height, weight, political leanings, conviviality, etc, each assigned a number. As he adds and removes numbers from his system, can you keep track of what the median value is? Warning, you might be working with a LOT of data!

The median of M numbers is defined as the middle number after sorting them in order if M is odd. Or it is the average of the middle two numbers if M is even. You start with an empty number list. Then, you can add numbers to the list, or remove existing numbers from it. After each add or remove operation, output the median.

Input Format

The first line is an integer, N, that indicates the number of operations. Each of the next N lines is either "a x" or "r x", with 'x' being an integer. An "a x" indicates that the value x is inserted (added) into the set, and "r x" indicates that the value x is removed from the set.

Constraints

1 ≤ N ≤ 106
-2,147,483,649 ≤ x ≤ 2,147,483,648
Output Format

For each operation:

If the operation is remove and the number x is not in the list, output "Wrong!" in a single line.
If the operation is remove and the number x is in the list, output the median after deleting x in a single line.
NOTE: If your median is 3.0, print only 3. And if your median is 3.50, print only 3.5. Whenever you need to print the median and the list is empty, print "Wrong!".
*/

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <map>
#include <limits.h>

using namespace std;

void display(map<long long, int> &m1, map<long long, int> &m2, int sLess, int sGreat, int i)
{
	cout << "OUTPUT: \n"<< i << endl;
	cout << "DISPLAYING MAP LESS 1:" << endl;
	for (auto item: m1)
	{
		cout << item.first << ": " << item.second << endl;
	}
	cout << "DISPLAYING MAP LESS SIZE:" << endl;
	cout << sLess << endl;
	
	cout << "DISPLAYING MAP GREAT 2:" << endl;
	for (auto item: m2)
	{
		cout << item.first << ": " << item.second << endl;
		cout << sGreat << endl;
	}
	cout << "DISPLAYING MAP GREAT SIZE:" << endl;
	cout << sLess << endl;
}

void redoSizes(map<long long, int> &less, map<long long, int> &great, int &sLess, int &sGreat)
{
	if (sLess > sGreat + 1)
	{
		less[less.rbegin()->first]--;
		great[less.rbegin()->first]++;
		if (less.rbegin()->second == 0)
		{
			less.erase(less.rbegin()->first);
		}
		sLess--;
		sGreat++;
	}
	else if (sGreat > sLess + 1)
	{
		great[great.begin()->first]--;
		less[great.begin()->first]++;
		if (great.begin()->second == 0)
		{
			great.erase(great.begin()->first);
		}
		sGreat--;
		sLess++;
	}
	return;
}

long double getMedian(map<long long, int> &less, map<long long, int> &great, int &sLess, int &sGreat)
{
	redoSizes(less, great, sLess, sGreat);
	long long med;
	if (sLess > sGreat)
	{
		cout << less.rbegin()->first << endl;
		return less.rbegin()->first;
	}
	else if (sGreat > sLess)
	{
		cout << great.begin()->first << endl;
		return great.begin()->first;
	}
	else
	{
		long long a = less.rbegin()->first;
		long long b = great.begin()->first;
		long double t = (long double)(a+b) / 2;
		if ((a+b)%2)
		{
			printf("%.1Lf\n", t);
		}
		else
		{
			printf("%lld\n", (long long)t);
		}
		return t;
	}
}

int main()
{
	int ops;
	cin >> ops;
	// max heap to store numbers smaller than current median
    map<long long, int> less; 
  
    // min heap to store numbers greater than current median
    map<long long, int> great;
    
    char op;
    long long num;
    
    int sLess = 0;
    int sGreat = 0;
    
    long double median = 0;
    
    for (int i = 0; i < ops; i++)
    {
    	cin >> op >> num;
    	if (op == 'r')
    	{
    		if(less.find(num) == less.end() && great.find(num) == great.end())
    		{
    			cout << "Wrong!" << endl;
    			continue;
    		}
    		else if(less.find(num) != less.end())
    		{
    			less[num]--;
    			if (less[num] == 0)
    			{
    				less.erase(num);
    			}
    			sLess--;
    			if (sLess == 0 && sGreat == 0)
				{
					cout << "Wrong!" << endl;
					continue;
				}
       			median = getMedian(less, great, sLess, sGreat);
    		}
    		else if(great.find(num) != less.end())
    		{
    			great[num]--;
    			if (great[num] == 0)
    			{
    				great.erase(num);
    			}
    			sGreat--;
    			if (sLess == 0 && sGreat == 0)
				{
					cout << "Wrong!" << endl;
					continue;
				}
    			median = getMedian(less, great, sLess, sGreat);
    		}
    	}
    	else if (op == 'a')
    	{
    		if (num <= median)
    		{
    			less[num] += 1;
    			sLess += 1;
        		median = getMedian(less, great, sLess, sGreat);
    		}
    		else
    		{
    			great[num] += 1;
    			sGreat += 1;
    			median = getMedian(less, great, sLess, sGreat);
    		}
    	}
    }
	return 0;
}
