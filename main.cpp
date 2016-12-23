#include <string>
#include <typeinfo>
#include <stdio.h>
#include <unistd.h>

#include "avltree.h"
#include "graph.h"
#include "graph_utils/utils.h"

/**
* struct to hold article link metadata
*/
typedef struct {
	// article name; possibly have it be a vector to include aliases?
	string name;
	// hardlink, i.e. /wiki/_____ <--
	string hlink;
} artlink_t;

int cmp(const int &a, const int &b) {
	return (a > b) ? 1 : (a == b) ? 0 : -1;
}

int artlink_cmp(const artlink_t &a, const artlink_t &b) {
	return (a.hlink > b.hlink) ? 1 : (a.hlink == b.hlink) ? 0 : -1;
}

int main(int argc, char **argv) {
	string s = "hello|name,2,1";
	NodeChildPair *p = parseLine(s, '|', ',');
	for(auto str : p->second) {
		cout << str << endl;
	}
	delete p;
	/*if(argc == 2) {
		char *fname = argv[1];
		if(access(fname, F_OK) == 0) {
			FILE *input_file = fopen(fname, "r");
			cout << (int)fgetc(input_file) << endl;
			fclose(input_file);
		} else {
			cout << "file does not exist" << endl;
		}
	} else {

	}*/

	/*Graph<int> g(cmp);
	g.insert(5, 10);
	g.insert(5, 12);
	g.insert(7, 10);*/

	// following code prints all children of '5'
	/*auto node = g.find(5);
	if(node != g.end()) {
		for(auto it = (*node).begin(); it != (*node).end(); it++) {
			cout << *it << endl;
		}
	}*/

	/*for(auto it = g.begin(); it != g.end(); it++) {
		cout << it.key() << endl;
	}

	Graph<int>::node_iterator n = g.find(10);
	if(n != g.end()) {
		cout << n.key() << endl;
	}

	Graph<artlink_t> linkGraph(artlink_cmp);*/
	return 0;
}