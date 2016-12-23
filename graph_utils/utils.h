#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

/**
* struct to hold article link metadata
*/
typedef struct {
	// article name; possibly have it be a vector to include aliases?
	string name;
	// hardlink, i.e. /wiki/_____ <--
	string hlink;
} artlink_t;

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
NodeChildPair *parseLine(char *line, char pcdelim, char ccdelim);

bool operator==(const artlink_t& a, const artlink_t& b)
{
	return a.name == b.name && a.hlink == b.hlink;
}

#include "utils.cpp"
#endif