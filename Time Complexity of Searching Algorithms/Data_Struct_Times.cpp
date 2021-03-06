// Data_Struct_Times.cpp : Defines the entry point for the console application.
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
	int num_index, rndInt;
	double sum_timeLin = 0.0, max_timeLin = -10.0;
	double sum_timeBin = 0.0, max_timeBin = -10.0;
	double sum_timeInt = 0.0, max_timeInt = -10.0;
	double sum_timeRB = 0.0, max_timeRB = -10.0;

	//cout << "Megethos :" << numera_ms.size() << " 1os : " << numera_ms[0] << " 10os :" << numera_ms[9] << " 1000os : " << numera_ms[999] << " 100000os : " << numera_ms[99999] << endl;
	cout << " Time Metrics for time complexity comparison among linear, binary, interpolation & red-black inorder search algos. " << endl << endl << endl;

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++) {
		rndInt = rand() % 490000 + 10;

		clock_t begin = clock();
		num_index = linear_s(numera_ms, rndInt);
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

		sum_timeLin += elapsed_secs;
		max_timeLin = ((elapsed_secs > max_timeLin) && (elapsed_secs != 0)) ? elapsed_secs : max_timeLin;
	}
	printf("Average time for linear search was : %.6f sec. \n", (sum_timeLin / 100));
	printf("Max time for linear search was : %.6f sec. \n\n", max_timeLin);

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++) {
		rndInt = rand() % 490000 + 10;

		clock_t begin = clock();
		num_index = binary_s(numera_ms, rndInt);
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

		sum_timeBin += elapsed_secs;
		max_timeBin = ((elapsed_secs > max_timeBin) && (elapsed_secs != 0)) ? elapsed_secs : max_timeBin;
	}
	printf("Average time for binary search was : %.6f sec. \n", (sum_timeBin / 100));
	printf("Max time for binary search was : %.6f sec. \n\n", max_timeBin);

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++) {
		rndInt = rand() % 490000 + 10;

		clock_t begin = clock();
		num_index = interpolation_s(numera_ms, rndInt);
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / (double)CLOCKS_PER_SEC;

		sum_timeInt += elapsed_secs;
		max_timeInt = ((elapsed_secs > max_timeInt) && (elapsed_secs != 0)) ? elapsed_secs : max_timeInt;
	}
	printf("Average time for interpolation search was : %.6f sec. \n", (sum_timeInt / 100));
	printf("Max time for interpolation search was : %.6f sec. \n\n", max_timeInt);

	RedBlack rb;
	for (unsigned int i = 0; i<numera.size(); i++) {
		rb.input(numera[i]);
	}
	RedBlackNode* rooty = rb.get_r();
	// cout << endl;

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++) {
		rndInt = rand() % 490000 + 10;

		clock_t begin = clock();
		//cout << rndInt << endl;
		rb.rb_inorder_s(rooty, rndInt);
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / (double)CLOCKS_PER_SEC;

		sum_timeRB += elapsed_secs;
		max_timeRB = ((elapsed_secs > max_timeRB) && (elapsed_secs != 0)) ? elapsed_secs : max_timeRB;
	}
	printf("Average time for red-black tree search was : %.6f sec. \n", (sum_timeRB / 100));
	printf("Max time for red-black tree search was : %.6f sec. \n\n", max_timeRB);

	cout << " --------------------------------------------------------------------------------------------------------------- " << endl;

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
