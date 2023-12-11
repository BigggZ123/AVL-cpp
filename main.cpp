#include <iostream>
#include "BiTree.h"
#include <vector>
#include "NodeReader.h"
#include "BinarySearchTree.h"
using namespace std ;

template <typename T>
auto visit(BiTreeNode<T>* node) ->bool {
    cout << node->data << endl ;
    return true ;
}

int main() {
//    BinarySearchTree<int> bst ;
//    bst.root = new BiTreeNode<int>(10) ;
//    bst.Root() = new BiTreeNode<int>(100);
//    cout << bst.root->data << endl ;

    bsTree<int> bst([](int x , int y) -> bool {
        return x > y ;
    }) ;
    bst.insert(5);
    for (int i = 0 ; i < 10 ; i ++){
        if (i != 5)
        bst.insert(i);
    }

    bst.remove(7);
    InOrder<int>(bst.locate(5), [](BiTreeNode<int> * n )-> bool { cout << n->data << endl ; return true; });

}
