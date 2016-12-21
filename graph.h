#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <exception>
#include <algorithm>

#include "avltree.h"
#include "inorder_iterator.h"

using namespace std;

template <class K>
class Graph
{
/* Comparator: returns 1 if a > b, 0 of a == b, and -1 if a < b */
typedef int (*comparator)(const K &a, const K &b);
typedef typename AVLTree<K, vector<K>>::iterator node_iterator;

public:
	Graph(comparator);
	Graph(const Graph &other);
	~Graph();

	void addNode(const K &node);

	/**
	* Insert an element into the graph and add a child onto the graph.
	*/
	void insert(const K &parent, const K &child);

	node_iterator find(const K &node);
	node_iterator contains(const K &node);

	node_iterator end();

private:
	comparator _cmp;
	/**
	*	Tree representation of graph:
	*		Key represents a node on the graph
	*		Value is a vector of all the children of that node
	* 	Note:
	* 		All values in children vector must be a key in the AVLTree
	* 		i.e. no child of a node on the graph is not a node itself
	*/
	AVLTree<K, vector<K>> data;

	bool hasChild(const vector<K> &childArray, const K &child);
};

#include "graph.cpp"
#endif