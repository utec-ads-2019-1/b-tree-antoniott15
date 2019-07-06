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
    BTree(unsignele d int degree) : degree(degree), root(nullptr){};


    T search(int k)
    { 
         return (root == NULL)? NULL : root->search(k); 
    }

    Node<T> *Node<T>::search(int k){
        int i = 0;
        while (i < size && k > keys.at(i)){
            i++;
        }
        if(keys.at(i) == k){
            return this;
        }
        if (isLeaf)
        {
            return NULL;
        }

        return childs.at(i)->search(k);
    }   

    void insert(int k){
        if(root!=NULL)
        {
            if (root->size == 2 * degree - 1)
            {
                Node<T> *newNode = new Node<T>(degree, false);
                newNode->childs.at(0) = root;
                newNode->split(0, root);
                int i = 0;
                if (newNode->keys.at(0) < k)
                {
                    i++;
                }
                newNode->childs.at(i)->insertEmpty(k);
                root = newNode;
            }
            else
            {
                root->insertEmpty(k);
            }
        }else{
            root = new Node<T>(degree, false);
            root->keys[0] = k;
            root->size = 1;
        }
    }

    void *Node<T>::insertNotEmpty(int k){
        int i = size - 1;
        if(isLeaf){
            while (i >= 0 && keys.at(i) > k)
            {
                keys[i + 1] = keys.at(i);
                i--;
            }
            keys[i+1] = k;
            size++;
        }
        else{
            while(i>=0&&keys.at(i)>k){
                i--;
            }
            if(childs[i+1]->size == 2*degree-1){
                Node<T> *newNode = new Node<T>(childs.at(i + 1)->degree, childs.at(i + 1)->isLeaf)
                newNode->size = degree - 1;
                for(int i = 0;j<degree-1;i++){
                    newNode->keys[i] = childs.at(i+1)->childs.at(i+degree);
                }
            }
        }
    }

    void Node<T>::print(){
            if (isLeaf)
            {
                for (int i = 0; i < size; i++)
                {
                    cout << keys[i] << "\t";
                }
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    childs[i]->print();
                    cout << keys[i] << "\t";
                }
                childs[size]->print();
            }
        }
    void print(){
        if (root)
        {
            root->print();
        }
        cout << "\n";
        
    }
};

#endif