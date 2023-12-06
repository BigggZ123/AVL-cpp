#include <iostream>
#include "BiTree.h"
#include <vector>
#include "NodeReader.h"
#include "BinarySearchTree.h"
using namespace std ;

int main() {
//    BinarySearchTree<int> bst ;
//    bst.root = new BiTreeNode<int>(10) ;
//    bst.Root() = new BiTreeNode<int>(100);
//    cout << bst.root->data << endl ;

    bsTree<int> bst([](int x , int y) -> bool {
        return x > y ;
    }) ;

    bst.insert(0);
    bst.insert(-1);
    bst.insert(1);

    cout << bst.root->RChild->data << endl ;
    cout << bst.root->LChild->data << endl ;
//
//    READ(bst.root) ;

    return 0;
}
