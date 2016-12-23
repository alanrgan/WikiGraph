#include <string>
#include <typeinfo>
#include <stdio.h>
#include <unistd.h>
#include <deque>
#include <map>
#include <queue>

#include "avltree.h"
#include "graph.h"
#include "graph_utils/utils.h"

int cmp(const int &a, const int &b)
{
	return (a > b) ? 1 : (a == b) ? 0 : -1;
}

int artlink_cmp(const artlink_t &a, const artlink_t &b)
{
	return (a.hlink > b.hlink) ? 1 : (a.hlink == b.hlink) ? 0 : -1;
}

artlink_t create_artlink(string name, string hlink)
{
	artlink_t alink;
	alink.name = name;
	alink.hlink = hlink;
	return alink;
}

deque<string> bfs(Graph<artlink_t> &g, string query_start, string query_end)
{
	map<string, bool> visited;
	// second element specifies parent of node
	deque<string> path;
	map<string, string> parents;
	queue<string> bfs_queue;

	bool found = false;

	Graph<artlink_t>::node_iterator it;
	auto end_it = g.find(create_artlink(query_end, query_end));

	bfs_queue.push(query_start);

	while(!bfs_queue.empty() && !found) {
		string curNode = bfs_queue.front();
		visited[curNode] = true;
		bfs_queue.pop();
		it = g.find(create_artlink(curNode, curNode));
		if(it != g.end()) {
			for(artlink_t child : *it) {
				if(!visited[child.name]) {
					if(child.name == query_end)
						found = true;
					parents[child.name] = curNode;
					bfs_queue.push(child.name);
				}
			}
		}
	}

	if(found) {
		string s = query_end;
		while(s != string()) {
			path.push_back(s);
			s = parents[s];
		}
	} else {
		cout << "could not connect nodes" << endl;
	}

	return path;
}

/**
* Note on input file format:
* 	Each line represents a node and its children.
* 	A parent is separated by its children by a '|'.
* 	A child is separated by a comma, ','.
*
* 	E.g:
*   parent|child1,child2,child3
*   othernode|ochild1,ochild2
*
*/
int main(int argc, char **argv) {
	// Below is a simple pathfinder between two nodes in a graph
	// usage: ./wikigraph <input_file> <start_node> <end_node>

	Graph<artlink_t> g(artlink_cmp);
	if(argc == 4) {
		char *fname = argv[1];
		if(access(fname, F_OK) == 0) {
			FILE *input_file = fopen(fname, "r");
			char *line = NULL;
			size_t buffer = 0;
			while(getline(&line, &buffer, input_file) != -1) {
				if(line[strlen(line)-1] == '\n')
					line[strlen(line)-1] = '\0';
				NodeChildPair *p = parseLine(line, '|', ',');
				for(auto str : p->second) {
					g.insert(create_artlink(p->first, p->first), create_artlink(str, str));
				}
				delete p;
			}
			fclose(input_file);
		} else {
			cout << "file does not exist" << endl;
			return 1;
		}

		for(auto a : bfs(g, argv[2], argv[3])) {
			cout << a << endl;
		}
	} else {

	}

	/*for(auto it = g.begin(); it != g.end(); it++) {
		cout << it.key().name << endl;
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