template <class K, class V>
AVLTree<K, V>::AVLTree(int (*comparator)(const K &a, const K &b))
    : root(NULL), cmp(comparator)
{
}

template <class K, class V>
AVLTree<K, V>::AVLTree(const AVLTree& other)
    : root(copy(other.root)), cmp(other.cmp)
{
}

template <class K, class V>
AVLTree<K, V>::~AVLTree()
{
    clear(root);
}

template <class K, class V>
const AVLTree<K, V>& AVLTree<K, V>::operator=(const AVLTree& rhs)
{
    if (this != &rhs) {
        clear(root);
        root = copy(rhs.root);
    }
    return *this;
}

template <class K, class V>
void AVLTree<K, V>::clear()
{
    clear(root);
    root = NULL;
}

template <class K, class V>
typename AVLTree<K, V>::Node* AVLTree<K, V>::copy(const Node* subRoot)
{
    if (subRoot == NULL)
        return NULL;

    // Copy this node and its children
    Node* newNode = new Node(subRoot->key, subRoot->value, subRoot->parent);
    newNode->left = copy(subRoot->left);
    newNode->right = copy(subRoot->right);
    return newNode;
}

template <class K, class V>
void AVLTree<K, V>::clear(Node* subRoot)
{
    if (subRoot == NULL)
        return;

    clear(subRoot->left);
    clear(subRoot->right);
    delete subRoot;
}

template <class K, class V>
void AVLTree<K, V>::swap(Node*& first, Node*& second)
{
    K tempkey = first->key;
    V tempvalue = first->value;
    Node *tmpparent = first->parent;
    first->key = second->key;
    first->value = second->value;
    first->parent = second->parent;
    second->key = tempkey;
    second->value = tempvalue;
    second->parent = tmpparent;
}
