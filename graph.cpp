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

/**
* If a child is not already in graph, then it is automatically added
*/
template <class K>
void Graph<K>::insert(const K &parent, const K &child)
{
	if(_cmp(parent, child) == 0) {
		cout << "A node cannot be its own parent" << endl;
		return;
	}

	node_iterator parentNode;
	// if the parent doesn't exist in the graph already, add it
	if((parentNode = data.find(parent)) == data.end())
		parentNode = data.insert(parent, vector<K>());

	// if child does not exist yet, then add
	if(data.find(child) == data.end())
		data.insert(child, vector<K>());

	// add child to the children-vector of the parent node
	if(child && !hasChild(*parentNode, child))
		(*parentNode).push_back(child);
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
typename Graph<K>::node_iterator Graph<K>::begin()
{
	return data.begin();
}

template <class K>
typename Graph<K>::node_iterator Graph<K>::end()
{
	return data.end();
}

