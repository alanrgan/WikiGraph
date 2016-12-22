#ifndef INORDER_ITERATOR_H
#define INORDER_ITERATOR_H

#include <stdexcept>
#include "../avltree.h"

using namespace std;

template<class K, class V>
class AVLTree;

template <typename K, typename V>
class inorder_iterator
{
    friend class AVLTree<K, V>;

public:
    typedef typename AVLTree<K, V>::Node treenode;

    inorder_iterator();
    ~inorder_iterator();

    bool operator== (const inorder_iterator& rhs) const;
    bool operator!= (const inorder_iterator& rhs) const;

    const V& operator*() const;
    V& operator*();

    inorder_iterator& operator++();
    inorder_iterator operator++(int);

    inorder_iterator& operator--();
    inorder_iterator operator--(int);

    inorder_iterator next();
    // returns null iterator if current iterator is tree.begin()
    inorder_iterator prev();

    const K& key() const;

private:
    const treenode *ptr;
    const AVLTree<K, V> *tree;

    //inorder_iterator(treenode *p, AVLTree<K, V> *t) : ptr(p), tree(t) {}
    inorder_iterator(const treenode *p, const AVLTree<K, V> *t) : ptr(p), tree(t) {}

};

#include "inorder_iterator.cpp"

#endif
