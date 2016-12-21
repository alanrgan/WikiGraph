/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

template <class K, class V>
typename AVLTree<K, V>::iterator AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
typename AVLTree<K, V>::iterator AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return iterator(NULL, this);
    else if (cmp(key, subtree->key) == 0)
        return iterator(subtree, this);//subtree->value;
    else {
        if (cmp(key, subtree->key) < 0)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
typename AVLTree<K, V>::iterator AVLTree<K, V>::begin()
{
    Node *cur = root;
    if(cur != NULL) {
        while(cur->left != NULL)
            cur = cur->left;
    }
    return iterator(cur, this);
}

template <class K, class V>
typename AVLTree<K, V>::iterator AVLTree<K, V>::end()
{
    return iterator(NULL, this);
}

template <class K, class V>
bool AVLTree<K, V>::empty()
{
    return root == NULL;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    Node *tempParent = t->parent;
    Node* temp = t->right->left;
    Node* rightChild = t->right;
    t->parent = rightChild;
    t->right->left = t;
    if(temp)
        temp->parent = t;
    t->right = temp;
    t = rightChild;
    t->parent = tempParent;
    // readjust the heights
    t->left->height = max(height(t->left->left), height(t->left->right))
                      + 1;
    t->height = max(height(t->left), height(t->right)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    Node *tempParent = t->parent;
    Node* temp = t->left->right;
    Node* leftChild = t->left;
    t->parent = leftChild;
    t->left->right = t;
    if(temp)
        temp->parent = t;
    t->left = temp;
    t = leftChild;
    t->parent = tempParent;
    // readjust the heights
    t->right->height = max(height(t->right->left), height(t->right->right)) + 1;
    t->height = max(height(t->left), height(t->right)) + 1;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    if(!subtree) return;
    if(balance(subtree) == -2) {
        if(balance(subtree->left) == -1)
            rotateRight(subtree);
        else
            rotateLeftRight(subtree);
    } else if(balance(subtree) == 2) {
        if(balance(subtree->right) == 1)
            rotateLeft(subtree);
        else
            rotateRightLeft(subtree);
    }

}

template <class K, class V>
int AVLTree<K, V>::balance(Node*& subtree)
{
    if(!subtree || (!subtree->left && !subtree->right))
        return 0;
    return height(subtree->right) - height(subtree->left);
}

template <class K, class V>
typename AVLTree<K, V>::iterator AVLTree<K, V>::insert(const K & key, const V & value)
{
    return insert(root, key, value, nullptr);
}

template <class K, class V>
typename AVLTree<K, V>::iterator AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value, Node *parent)
{
    if(!subtree) {
        subtree = new Node(key, value, parent);
    }
    else if(cmp(key, subtree->key) < 0)
        insert(subtree->left, key, value, subtree);
    else if(cmp(key, subtree->key) > 0)
        insert(subtree->right, key, value, subtree);
    rebalance(subtree);
    subtree->height = max(height(subtree->left), height(subtree->right)) + 1;
    return iterator(subtree, this);
}

template <class K, class V>
int AVLTree<K, V>::height(Node*& subtree) const
{
    if(!subtree) return -1;
    else if(!subtree->left && !subtree->right) {
        return 0;
    } else
        return subtree->height;
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (cmp(key, subtree->key) < 0) {
        remove(subtree->left, key);
    } else if (cmp(key, subtree->key) > 0) {
        remove(subtree->right, key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            Node* temp = subtree;
            subtree = NULL;
            delete temp;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            Node* & _iop = iop(subtree->left);
            swap(subtree, _iop);
            remove(subtree->left, _iop->key);
            _iop = NULL;
        } else {
            /* one-child remove */
            Node*& temp = subtree;
            if(subtree->left == NULL)
                subtree = subtree->right;
            else 
                subtree = subtree->left;
            subtree->parent = temp->parent;
            delete temp;
            temp = NULL;
        }
    }
    if(subtree)
        subtree->height = max(height(subtree->left), height(subtree->right)) + 1;
    rebalance(subtree);
}

template <class K, class V>
typename AVLTree<K, V>::Node* & AVLTree<K, V>::iop(Node*& subtree) const
{
    if(subtree->right == NULL) return subtree;
    else return iop(subtree->right);
}

// for testing purposes
template <class K, class V>
void AVLTree<K, V>::convertHeight()
{
    convertHeight(root);
}

// for testing purposes
template <class K, class V>
void AVLTree<K, V>::convertHeight(Node*& subRoot)
{
    if(subRoot) {
        subRoot->key = subRoot->height;
        convertHeight(subRoot->left);
        convertHeight(subRoot->right);
    }
}
