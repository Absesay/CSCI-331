
#include <iostream>
#include <vector>
#include "Location.h"

using namespace std;

template <class T>
void swap_loc(vector<T> &aVector, const int &i, const int &j)
{
	T temp = aVector[i];
	aVector[i] = aVector[j];
	aVector[j] = temp;
}

template <class T>
void insertSort (vector<T> &anArray, const int &first, const int &last)
{
	// unsorted = first index of the unsorted region
	// loc = last index the sorted region + 1
	// nextItem = next item in the sorted region (the current item that is being placed to the sorted region)
	for (int unsorted = first + 1; unsorted <= last; unsorted++)
	{
		// sorted region is anArray[0..unsorted-1]
		
		// get the next item
		T nextItem = anArray[unsorted];	
		// get the right most index of sorted region + 1 (increase size by 1)
		int loc = unsorted;
		
		// shift right to make room for the nextItem
		while ((loc > 0) && anArray[loc - 1] > nextItem)
		{
			anArray[loc] = anArray[loc - 1];
			loc--;
		}
		
		// place the next item to the correct position
		anArray[loc] = nextItem;
	}
}

/* This function sort 3 first, mid, last entries in increasing order
	@pre: first <= mid <= last.
	@post: first, mid, last entries are sorted in increasing order
	@param: anArray - a given array
			first: first index of the first half
			mid: last index of the first half
			last: last index of the second half */
template <class T>
void sortFirstMidLast (vector<T> &anArray, const int &first, const int &mid, const int &last)
{
	if (anArray[first] > anArray[mid])
	{ swap_loc(anArray, first, mid); }
	
	if (anArray[mid] > anArray[last])
	{ swap_loc(anArray, mid, last); }
	
	if (anArray[first] > anArray[mid])
	{ swap_loc(anArray, first, mid); }
}

template <class T>
int partition (vector<T> &anArray, const int &first, const int &last)
{
	// get the middle index
	int mid = first + (last - first)/2;
	// sort first, mid, last
	sortFirstMidLast(anArray, first, mid, last);
	
	// swap the middle index with the last - 1
	swap_loc(anArray, mid, last - 1);
	
	// make that pivot
	int pivotIndex = last - 1;
	T pivot = anArray[pivotIndex];
	
	// start checking from left and right
	int indLeft = first + 1;
	int indRight = last - 2;
	bool done = false;
	while (!done)
	{	
		// look for the larger than pivot in the left
		while (anArray[indLeft] < pivot)
		{
			indLeft++;
		}
		
		// look for smaller than pivot in the right
		while (anArray[indRight] > pivot)
		{
			indRight--;
		}
		
		// swap them if they are in the wrong side
		if (indLeft < indRight)
		{
			swap_loc(anArray, indLeft, indRight);
			indLeft++;
			indRight--;
		}
		
		// done with the current pivot
		else
		{
			done = true;
		}
	}
	
	// swap again to place the pivot to the correct position
	swap_loc(anArray, pivotIndex, indLeft);

	return indLeft;
}

inline void qSort(vector<Location> &anArray, const int &first, const int &last)
{
	if (last - first > 0)
	{
		// if the array size is less than 4, use insert sort
		if ((last - first + 1) < 4)
		{
			insertSort(anArray, first, last);
		}
		// quick sort here
		else
		{
			// find the pivot index
			int pivotIndex = partition(anArray, first, last);
			
			// divide the array and use quick sort for the 2 subarrays
			qSort(anArray, first, pivotIndex - 1);
			qSort(anArray, pivotIndex + 1, last);
		}	
	}
}
