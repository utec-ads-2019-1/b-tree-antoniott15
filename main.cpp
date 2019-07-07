#include <iostream>

#include "btree.h"

using namespace std;

int main(int argc, char *argv[]) {
    BTree<int> test(10);

    for (int i = 0; i < 20; i++)
        test.insert(i);

    test.print();


    
    system("pause");
    return EXIT_SUCCESS;
}