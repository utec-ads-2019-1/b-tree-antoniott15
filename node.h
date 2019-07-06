#ifndef NODE_H
#define NODE_H

#include <vector>
#include "btree.h"
using namespace std;

template <typename T>
class Node {
    unsigned int size;
    vector<unsigned int> keys;
    vector<Node<T>*> childs;
    bool isLeaf;

    public: 
        Node(unsigned int size, bool isLeaf = true) : size(size), isLeaf(isLeaf) {
            keys.resize(size - 1);
            childs.resize(size);
        }

        /**
         * An alternative is to create two different nodes (Internal and Leaf) that inherite from Node 
         * an implement this function
         */


    friend class BTree; 
};

#endif