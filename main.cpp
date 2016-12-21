#include "avltree.h"
#include "graph.h"

int cmp(const int &a, const int &b) {
	return (a > b) ? 1 : (a == b) ? 0 : -1;
}

int main() {
	Graph<int> g(cmp);
	g.addNode(5);
	g.insert(5, 10);
	g.insert(5, 12);
	g.addNode(10);
	g.addNode(12);

	// following code prints all children of '5'
	auto node = g.find(5);
	if(node != g.end()) {
		for(auto it = (*node).begin(); it != (*node).end(); it++) {
			cout << *it << endl;
		}
	}
	return 0;
}