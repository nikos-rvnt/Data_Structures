/*
Merge sort is a sorting technique based on divide and conquer technique.With worst-case time complexity
being Ο(n log n), it is one of the most respected algorithms.Merge sort first divides the array into equal
halves and then combines them in a sorted manner.
	*Step 1 − if it is only one element in the list it is already sorted, return.
	*Step 2 − divide the list recursively into two halves until it can no more be divided.
	*Step 3 − merge the smaller lists into new list in sorted order.
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

vector<int> merging(vector<int> vina, vector<int> vinb) {

	vector<int> vout;

	while (!vina.empty() && !vinb.empty() )
	{
		if (vina.front() > vinb.front()) {
			vout.push_back(vinb.front());
			vinb.erase(vinb.begin());
		}
		else {
			vout.push_back(vina.front());
			vina.erase(vina.begin());
		}
	}

	while (!vina.empty())
	{
		vout.push_back(vina.front());
		vina.erase(vina.begin());
	} 

	while(!vinb.empty())
	{
		vout.push_back(vinb.front());
		vinb.erase(vinb.begin());
	}

	/*for (unsigned int i = 0; i < vout.size(); i++) {
		cout << vout[i] << endl;
	}*/
	//cout << "Megethos : " << vout.size();

	return vout;
}

vector<int> merge_sort(vector<int> vin) {

	if (vin.size() == 1)
		return vin;

	vector<int>::iterator it = vin.begin();
	vector<int>::iterator it2 = vin.begin() + (vin.size() / 2 );
	vector<int> v1, v2;
	v1.assign(it, vin.begin() + vin.size() / 2);
	v2.assign(it2, vin.end());

	//cout << v1.size() << "--" << v2.size() << endl;

	v1 = merge_sort(v1);
	v2 = merge_sort(v2);

	//cout << v1.size() << "--" << v2.size();

	return merging(v1, v2);
}
