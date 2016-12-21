template <class K>
Graph<K>::Graph(comparator cmp) : _cmp(cmp), data(AVLTree<K, vector<K>>(cmp))
{
}

template <class K>
Graph<K>::~Graph()
{
}

template <class K>
void Graph<K>::addNode(const K &node)
{
	data.insert(node, vector<K>());
}

template <class K>
void Graph<K>::insert(const K &parent, const K &child)
{
	if(_cmp(parent, child) == 0) {
		cout << "A node cannot be its own parent" << endl;
		return;
	}

	node_iterator parentNode;
	// if parent exists on the graph already
	if((parentNode = data.find(parent)) != data.end()) {
		// then add the child to the parent if the parent doesn't already have the child
		if(child && !hasChild(*parentNode, child))
			(*parentNode).push_back(child);
	} else {
		// otherwise add the parent to the graph
		node_iterator node = data.insert(parent, vector<K>());
		if(child && !hasChild(*parentNode, child))
			(*node).push_back(child);
	}
}

template <class K>
bool Graph<K>::hasChild(const vector<K> &childArray, const K &child)
{
	return std::find(childArray.begin(), childArray.end(), child) != childArray.end();
}

template <class K>
typename Graph<K>::node_iterator Graph<K>::find(const K &key)
{
	return data.find(key);
}

template <class K>
typename Graph<K>::node_iterator Graph<K>::contains(const K &key)
{
	return data.find(key) != data.end();
}

template <class K>
typename Graph<K>::node_iterator Graph<K>::end()
{
	return data.end();
}

