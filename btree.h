#ifndef BTREE_H
#define BTREE_H

#include "node.h"

template <typename T>
class BTree
{
private:
    Node<T> *root;
    unsigned int degree;

public:
    BTree(unsigned int degree) : degree(degree), root(nullptr){};

    Node<T> search(int k)
    { 
         return (root == NULL)? NULL : root->search(k); 
    }

    void insert(int k){
        if(root!=NULL)
        {
            if (root->size == 2 * degree - 1)
            {
                Node<T> *newNode = new Node<T>(degree, false);
                newNode->childs.at(0) = root;
                newNode->splitChild(0, root);
                int i = 0;
                if (newNode->keys.at(0) < k)
                {
                    i++;
                }
                newNode->childs.at(i)->insert(k);
                root = newNode;
            }
            else
            {
                root->insert(k);
            }
        }else{
            root = new Node<T>(degree, false);
            root->keys[0] = k;
            root->size = 1;
        }
    }


    void print(){
        if (root)
        {
            root->print();
        }
    }


};

#endif