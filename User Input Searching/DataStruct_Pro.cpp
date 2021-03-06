// DataStruct_Pro.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>  
#include <fstream>      
#include <sstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>    
#include <iterator>     

#include <cassert>
#include <stdlib.h>     /* srand, rand */
#include <ctime>       /* time */

//#include <boost/iostreams/device/mapped_file.hpp>
//#include <boost/iostreams/stream.hpp>
//#include <boost/intrusive/rbtree_algorithms.hpp>

#include "merge.h" 
#include "linear.h"
#include "binary.h"
#include "interpolation.h"
#include "red_black.h"

#define NULL 0

using namespace std;

vector<int> readInFile(string);

int main()
{
	vector<int> numera = readInFile("integers.txt");
	vector<int> numera_ms = merge_sort(numera);
	int num_s, num_index, s_choice, rndInt;
	double sum_timeLin = 0.0, min_timeLin = 10000.0;
	double sum_timeBin = 0.0, min_timeBin = 10000.0;
	float sum_timeInt = 0.0, min_timeInt = 10000.0;

	//cout << "Megethos :" << numera_ms.size() << " 1os : " << numera_ms[0] << " 10os :" << numera_ms[9] <<" 1000os : " << numera_ms[999] << " 100000os : " << numera_ms[99999] << endl;
	
	RedBlack rb;
	for (unsigned int i = 0; i<numera.size(); i++) {
		//cout << numera[i] << endl;
		rb.input(numera[i]);
	}
	RedBlackNode* rooty = rb.get_r();
	//cout << "H riza: " << rooty->num << endl;

	cout << "************************************ Searching a number in the integers.txt file! ***********************************" << endl;
	cout << "Give a number to check if exists in the .txt file :" << endl;
	cin >> num_s;
	cout << "Now, choose one of the following search methods :" << endl;
	cout << "\t\t 1. Linear Search" << endl << "\t\t 2. Binary Search" << endl << "\t\t 3. Interpolation Search" << endl << "\t\t 4. RedBlack InOrder Traversal Search" << endl;
	cin >> s_choice;

	switch (s_choice) {
		case 1:
			num_index = linear_s(numera_ms, num_s);
			break;
		case 2:
			num_index = binary_s(numera_ms, num_s);
			break;
		case 3:
			num_index = interpolation_s(numera_ms, num_s);
			break;
		case 4:
			num_index = rb.rb_inorder_s(rooty,num_s);
			break;
		default:
			cout << "Invalid choice number." << endl;
			break;
	}

	if (num_index && s_choice!=4)
		printf("Number %d exists and is placed in %dth position of sorted file. \n", num_s, num_index);
	else if ((num_index && s_choice == 4))
		printf("Number %d exists and was found %d nodes height down of the root of red-black tree. \n", num_s, num_index);
	else
		printf("Number %d does not exist in the .txt file. \n",num_s);
	
	return 0;
	
}

vector<int> readInFile(string f)
{
/*	boost::iostreams::stream<boost::iostreams::mapped_file_source> str(f);
	vector<int> app;
	
	for(string x; getline( str, x, '\n');)
	{
		app.push_back(stoi(x));
	}
	*/
	ifstream file;
	file.open(f);
	string value;
	vector<int> app;
	int i = 0;

	//getline(file, value);
	// read line by line
	while (getline(file, value))
	{
		//cout << " " << value << endl;
		app.push_back(stoi(value));
		i++;
	}
	//cout << app.size() << endl << i;
	file.close();


	return app;
}
