/////////////////////////////////////////////////////
// Workshop 1 - Modular Programming (Home)
// Filename: graph.h
// Name: Samantha West
// Student ID: 128111168
// Date: 2017-05-18
/////////////////////////////////////////////////////

#include <iostream>
#define MAX_NO_OF_SAMPLES 20
#ifndef SICT_GRAPH_H
#define SICT_GRAPH_H

	namespace sict {

	// Fills the samples array with the statistic samples
	void getSamples(int samples[], int noOfSamples);
	// Finds the largest sample in the samples array, if it is larger than 70,
	// therwise it will return 70.
	int findMax(int samples[], int noOfSamples);
	// Prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max);
	// Prints a graph comparing the sample values visually
	void printGraph(int samples[], int noOfSamples);

}
#endif 
