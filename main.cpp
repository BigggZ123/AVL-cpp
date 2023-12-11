#include <iostream>
#include "BiTree.h"
#include <vector>
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
    vector<BiTreeNode<int>*> nodes ;
    nodes.reserve(10);
    for (int i =  0 ; i < 10 ; i ++){
        nodes.push_back(new BiTreeNode<int>(i));
    }
//    cout << nodes.size() << endl ;

    bsTree<int> bst ([](int x, int y) -> bool { return (x < y) ;});

    bst.insert(7);
    bst.insert(5);
    bst.insert(9);
    bst.insert(4);
    bst.insert(6) ;
    bst.insert(1);

//    cout << Balance_Factor(bst.root) << endl ;
    READ(AVLTree<int>::LRotate(bst.root));
}
