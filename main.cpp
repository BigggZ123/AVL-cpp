#include <iostream>
#include "BiTree.h"
#include <vector>
#include <chrono>
#include "NodeReader.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
using namespace std ;

template <typename T>
auto visit(BiTreeNode<T>* node) ->bool {
    cout << node->data << endl ;
    return true ;
}

int main() {
    AVLTree<int> avl([](int x , int y) {return x > y ;}) ;
    for (int i = 0 ; i < 10 ; i ++){
        avl.insert(i);
    }
    avl.remove(3);
    avl.remove(1);
//    cout << Balance_Factor(avl.root) << endl ;
    READ(avl.root);
}
