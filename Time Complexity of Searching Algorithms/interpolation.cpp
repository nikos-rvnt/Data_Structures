/*
Interpolation search finds a particular item by computing the probe position. Initially, the probe position is the position
of the middle most item of the collection. If the middle item is greater than the item, then the probe position is again 
calculated in the sub-array to the right of the middle item. Otherwise, the item is searched in the subarray to the left of
the middle item. This process continues on the sub-array as well until the size of subarray reduces to zero.
	*Step 1 − Start searching data from middle of the list.
	*Step 2 − If it is a match, return the index of the item, and exit.
	*Step 3 − If it is not a match, probe position.
	*Step 4 − Divide the list using probing formula and find the new midle.
	*Step 5 − If data is greater than middle, search in higher sub-list.
	*Step 6 − If data is smaller than middle, search in lower sub-list.
	*Step 7 − Repeat until match.
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int interpolation_s(vector<int> vin, int snum) {

	int index = 0;
	int low_bound = 0;
	int middle = -1;
	int up_bound = vin.size() - 1;

	while(!index){

		if (low_bound >= up_bound || vin[low_bound] == vin[up_bound])
			break;

		
		int middle = low_bound + ((up_bound - low_bound) / (vin[up_bound] - vin[low_bound])) * (snum - vin[low_bound]);

		if (vin[middle]==snum) {
			index = middle;
			break;
		}
		else if(vin[middle]<snum) {
			low_bound = middle + 1;
		}
		else if (vin[middle]>snum) {
			up_bound = middle - 1;
		}
		
	}	

	return index;
}
