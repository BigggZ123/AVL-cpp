//
// Created by lenovo on 2023/12/11.
//

#ifndef AVL_AVLTREE_H
#define AVL_AVLTREE_H

#include "BinarySearchTree.h"

const int max_balance_height = 1 ;


template <typename T>
class AVLTree : public BinarySearchTree<T>{
public :
    //据理解，构型检测不属于rotate的职责
    //这样才好将所谓的"左/右"旋有一个统一的理解
    //不妨这样记：所谓“左、右”，及当前节点在结果节点的左、右边
    static BiTreeNode<T>*       RRotate     (BiTreeNode<T>* node );
    static BiTreeNode<T>*       LRotate     (BiTreeNode<T>* node );
    static BiTreeNode<T>*       Rotate      (BiTreeNode<T>* node ) ;
};

template<typename T>
BiTreeNode<T> *AVLTree<T>::Rotate(BiTreeNode<T> *node) {
    int _balanceFactor = Balance_Factor(node);
    if (node > max_balance_height){

    }
    else if (node < -max_balance_height){

    }

    return node ;
}


template<typename T>
BiTreeNode<T> *AVLTree<T>::RRotate(BiTreeNode<T> *node) {
    if (node->LChild == nullptr){
        return node ;
    }

    auto child =  node->LChild ;
    auto grandeChild = node->LChild->RChild ;

    child->RChild = node ;
    node->LChild =  grandeChild ;
    return child ;
}

template<typename T>
BiTreeNode<T> *AVLTree<T>::LRotate(BiTreeNode<T> *node) {
    if (node->RChild == nullptr){
        return node ;
    }

    auto child =  node->RChild ;
    auto grandeChild = node->RChild->LChild ;

    child->LChild = node ;
    node->RChild =  grandeChild ;
    return child ;
}



#endif //AVL_AVLTREE_H
