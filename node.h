#ifndef NODE_H
#define NODE_H

#include <vector>
#include "btree.h"
using namespace std;
template <typename T>class BTree;
template <typename T>
class Node {
    unsigned int size;
    unsigned int degree;
    vector<unsigned int> keys;
    vector<Node<T>*> childs;
    bool isLeaf;

    public: 
        Node(unsigned int size, bool isLeaf = true) : size(size), isLeaf(isLeaf) {
            keys.resize(size - 1);
            childs.resize(size);
        }

        Node<T> search(int k)
        {
            int i = 0;
            while (i < size && k > keys.at(i))
            {
                i++;
            }
            if (keys.at(i) == k)
            {
                return;
            }
            if (isLeaf)
            {
                return NULL;
            }

            return childs.at(i)->search(k);
        }

        void insert(int k)
        {
            int i = size - 1;
            if (isLeaf)
            {
                while (i >= 0 && keys.at(i) > k)
                {
                    keys[i + 1] = keys.at(i);
                    i--;
                }
                keys[i + 1] = k;
                size++;
            }
            else
            {
                while (i >= 0 && keys.at(i) > k)
                {
                    i--;
                }
                if (childs[i + 1]->size == 2 * degree - 1)
                {
                    Node<T> *newNode = new Node<T>(childs.at(i + 1)->degree, childs.at(i + 1)->isLeaf);
                    newNode->size = degree - 1;
                    splitChild(i + 1, childs[i + 1]);
                    if (keys[i + 1] < k)
                        i++;
                }
                childs[i + 1]->insert(k);
            }
            
        }

        void splitChild(int k, Node<T> *valueTo)
        {
            Node<T> *newNode = new Node<T>(valueTo->degree, valueTo->isLeaf);
            newNode->size = degree -1;

            for (int i = 0; i < degree - 1; i++)
            {
                newNode->keys[i] = valueTo->keys[i + degree];
            }

            if (valueTo->isLeaf == false)
            {
                for (int i = 0; i < degree; i++)
                    valueTo->childs[i] = valueTo->childs[i + degree];
            }

            valueTo->size = degree - 1;
            for (int i = size; i >= k + 1; i--){
                childs[i + 1] = childs[i];
            }
            childs[k + 1] = newNode;

            for (int i = size - 1; i >= k; i--){
                keys[i + 1] = keys[i];
            }
            keys[k] = valueTo->keys[degree - 1];
            size++;
        }

        void print(){
            if (!isLeaf)
            {
                for (int i = 0; i < size; i++)
                {
                    childs[i]->print();
                    cout << keys[i] << "\t";
                }
            }
            else
            {
                childs[size]->print();
                for (int i = 0; i < size; i++)
                {
                    cout << keys[i] << "\t";
                }
            }
        }


        friend class BTree<T>;
};

#endif