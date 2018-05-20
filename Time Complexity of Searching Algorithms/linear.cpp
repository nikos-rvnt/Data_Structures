#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int linear_s(vector<int> vin, int snum) {

	int index = 0, i = 0;
	for (vector<int>::iterator it = vin.begin(); it != vin.end(); ++it)
	{
		if (*it == snum) {
			index = i;
			break;
		}
		i++;
	}

	return index;
}
