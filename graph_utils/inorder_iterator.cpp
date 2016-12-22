template <class K, class V>
inorder_iterator<K, V>::inorder_iterator() : ptr(NULL), tree(NULL)
{
}

template <class K, class V>
inorder_iterator<K, V>::~inorder_iterator()
{

}

template <class K, class V>
bool inorder_iterator<K, V>::operator==(const inorder_iterator& rhs) const
{
    return ptr == rhs.ptr;
}

template <class K, class V>
bool inorder_iterator<K, V>::operator!=(const inorder_iterator& rhs) const
{
    return ptr != rhs.ptr;
}

template <class K, class V>
inorder_iterator<K, V>& inorder_iterator<K, V>::operator++()
{
   treenode *p;

   if(ptr == NULL) {
       ptr = tree->root;
       if(ptr == NULL) {
           throw underflow_error("iterator operator++(): tree is empty");
       }
       while(ptr->left != NULL) {
           ptr = ptr->left;
       }
   } else {
       if(ptr->right != NULL) {
           ptr = ptr->right;
           while(ptr->left != NULL) {
               ptr = ptr->left;
           }
       } else {
           p = ptr->parent;
           while(p != NULL && ptr == p->right) {
               ptr = p;
               p = p->parent;
           }
           ptr = p;
       }
   }

   return *this;
}

template <class K, class V>
inorder_iterator<K, V> inorder_iterator<K, V>::operator++(int)
{
    return operator++();
}

template <class K, class V>
inorder_iterator<K, V>& inorder_iterator<K, V>::operator--()
{
    treenode *p;

    // if at null iterator, set iterator to last element of tree
    if(ptr == NULL) {
        ptr = tree->root;
        if(ptr == NULL) {
            throw underflow_error("iterator operator--(): tree is empty");
        }
        while(ptr->right != NULL) {
            ptr = ptr->right;
        }
    } else {
        if(ptr->left != NULL) {
            ptr = ptr->left;
            while(ptr->right != NULL) {
                ptr = ptr->right;
            }
        } else {
            p = ptr->parent;
            while(p != NULL && ptr == p->left) {
                ptr = p;
                p = p->parent;
            }
            ptr = p;
        }
    }

    return *this;
}

template <class K, class V>
inorder_iterator<K, V> inorder_iterator<K, V>::operator--(int)
{
    return operator--();
}

template <class K, class V>
inorder_iterator<K, V> inorder_iterator<K, V>::next()
{
    inorder_iterator<K, V> temp = *this;
    return temp++;
}

template <class K, class V>
inorder_iterator<K, V> inorder_iterator<K, V>::prev()
{
    inorder_iterator<K, V> temp = *this;
    return temp--;
}

template <class K, class V>
const K& inorder_iterator<K, V>::key() const
{
    return ptr->key;
}

template <class K, class V>
const V& inorder_iterator<K, V>::operator*() const
{
    return ptr->value;    
}

template <class K, class V>
V& inorder_iterator<K, V>::operator*()
{
	return const_cast<V&>(static_cast<const inorder_iterator*>(this)->operator*());
}
