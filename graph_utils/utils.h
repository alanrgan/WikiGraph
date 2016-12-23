#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

template <class T, class K>
struct Pair {
	T first;
	K second;
};

typedef Pair<string, vector<string>> NodeChildPair;

/**
* Sample line: parent|child1,child2,child3
* pcdelim: '|', ccdelim: ','
* 
* This function returns a Pair consisting of the parent node label and a vector of
* labels of child nodes. Note: it is up to the caller to free the memory allocated for the Pair
*
* @param pcdelim delimiter between parent node and children
* @param ccdelim delimiter between children
*/
NodeChildPair *parseLine(string &line, char pcdelim, char ccdelim);

#include "utils.cpp"
#endif