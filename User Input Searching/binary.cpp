/*
Binary search is a fast search algorithm with run-time complexity of Ο(log n). This search algorithm works on the principle 
of divide and conquer. For this algorithm to work properly, the data collection should be in the sorted form.Binary search 
looks for a particular item by comparing the middle most item of the collection. If a match occurs, then the index of item
is returned. If the middle item is greater than the item, then the item is searched in the sub-array to the left of the 
middle item. Otherwise, the item is searched for in the sub-array to the right of the middle item. This process continues 
on the sub-array as well until the size of the subarray reduces to zero.
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int binary_s(vector<int> vin, int snum) {

	int index = 0;
	int low_bound = 0;
	int up_bound = vin.size() - 1;

	while (!index) {

		if (up_bound < low_bound)
			break;

		int middle = low_bound + (up_bound - low_bound) / 2;

		if (vin[middle] < snum)
			low_bound = middle + 1;

		if (vin[middle] > snum)
			up_bound = middle - 1;

		if (vin[middle] == snum) {
			index = middle;
			break;
		}

	}

	return index;
}
