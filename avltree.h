#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <vector>
#include <sstream>
#include "graph_utils/inorder_iterator.h"

template <class K, class V>
class inorder_iterator;

using namespace std;

/**
 * The AVLTree class represents a linked-memory AVL Tree.
 * @tparam K the type of key stored in the tree
 * @tparam V the type of value stored in the tree
 */
template <class K, class V>
class AVLTree
{
    friend class inorder_iterator<K, V>;
 /* Comparator: returns 1 if a > b, 0 of a == b, and -1 if a < b */
 typedef int (*comparator)(const K &a, const K &b);
 public:
    typedef inorder_iterator<K, V> iterator;

    /**
     * Node represents a tree node; that is, an element in a AVLTree.
     * It stores a key, value, and pointers to its left and right children.
     */
    struct Node {
        K key;
        V value;
        Node* left;
        Node* right;
        Node* parent;
        int height;

        /**
         * Node constructor; sets children to point to `NULL`.
         * @param newKey The object to use as a key
         * @param newValue The templated data element that the constructed
         *  node will hold.
         */
        Node(const K& newKey, const V& newValue, Node* newParent)
            : key(newKey), value(newValue), left(NULL), right(NULL), parent(newParent), height(0)
        {
        }
    };

  public:
    /**
     * Constructor to create an empty tree.
     */
    AVLTree(int (*comparator)(const K &a, const K &b));

    /**
     * Copy constructor.
     * @param other The tree to copy
     */
    AVLTree(const AVLTree& other);

    /**
     * Destructor; frees all nodes associated with this tree.
     */
    ~AVLTree();

    /**
     * Assignment operator.
     * @param rhs The tree to copy
     * @return A reference to the current tree
     */
    const AVLTree& operator=(const AVLTree& rhs);

    /**
     * Frees all nodes associated with this tree and sets it to be empty.
     */
    void clear();

    bool empty();

    /**
     * Inserts a key and value into the AVLTree.
     * Nothing happens if inserting a key that already exists in the tree.
     * @param key The key to insert
     * @param value The value associated with the key
     * @return iterator to the node inserted
     */
    iterator insert(const K& key, const V& value);

    /**
     * Removes a key from the AVLTree. The key is assumed to exist in the tree.
     * @param key The key to remove
     */
    void remove(const K& key);

    /**
     * Returns an iterator to an element in the AVL tree.
     * Returns null iterator if element is not found
     * @param key The element to search for
     * @return iterator pointing to that key
     */
    iterator find(const K& key) const;

    iterator begin();

    iterator end();

    void convertHeight();
    
  private:
    /**
     * The root of the tree.
     */
    Node* root;
    comparator cmp;

     void convertHeight(Node*& subRoot);
    /**
     * Private helper function for the public #insert function.
     * @param node The current node in the recursion
     * @param key The key to insert
     * @param value The value associated with the key
     */
    iterator insert(Node*& node, const K& key, const V& value, Node *parent);

    /**
     * Private helper function for the public #remove function.
     * @param node The current node in the recursion
     * @param key The key to remove
     */
    void remove(Node*& node, const K& key);

    /**
     * Finds a value (by key) in the AVL tree.
     * @param node The node to search from (current subroot)
     * @param key The key to search for
     * @return The value stored for that key
     */
    iterator find(Node* node, const K& key) const;

    /**
     * Rotate the tree right (there is an imbalance on the left side).
     * @param node The node to rotate
     */
    void rotateRight(Node*& node);

    /**
     * Rotates the tree left (there is an imbalance on the right side).
     * @param node The node to rotate
     */
    void rotateLeft(Node*& node);

    /**
     * A right-left rotation.
     * This function should simply call rotateRight and rotateLeft.
     * @param node The node to rotate
     */
    void rotateRightLeft(Node*& node);

    /**
     * A left-right rotation.
     * This function should simply call rotateLeft and rotateRight.
     * @param node The node to rotate
     */
    void rotateLeftRight(Node*& node);

    /**
     * Rebalance a node by performing rotations. You can assume that node->left
     * and node->right are both balanced. Even if no rotations are required,
     * you should update the node's height.
     * @param node The node to balance.
     */
    void rebalance(Node*& node);

    /**
     * @param node The node's height to check
     * @return The height of the node if it's non-`NULL` or -1 if it is `NULL`
     */
    int heightOrNeg1(const Node* node) const;

    /**
     * Swap the keys and values of two nodes.
     * @param first The first node to swap
     * @param second The node to swap with
     */
    void swap(Node*& first, Node*& second);

    /**
     * Helper function for #operator= and AVLTree(const AVLTree &).
     * @param subRoot The current node in the recursion
     */
    Node* copy(const Node* subRoot);

    /**
     * Private helper function for clear that clears beneath the parameter node.
     * @param subRoot The current node in the recursion
     */
    void clear(Node* subRoot);

    int balance(Node*& subtree);

    Node* & iop(Node* & subtree) const;

    int height(Node*& subtree) const;

};

#include "avltree_given.cpp"
#include "avltree.cpp"
#endif
