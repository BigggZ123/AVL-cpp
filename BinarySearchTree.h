//
// Created by lenovo on 2023/12/7.
//

#ifndef AVL_BINARYSEARCHTREE_H
#define AVL_BINARYSEARCHTREE_H
#include "NodeReader.h"
#include "BiTree.h"
template <typename T>
class BinarySearchTree : public BiTree<T>{
public:
    bool                    insert      ( T data )  ;
    BiTreeNode<T>*          locate      ( T data );
    static BiTreeNode<T>*   Digout      ( BiTreeNode<T> node);
    bool                    remove      (T data) ;
    explicit BinarySearchTree (bool(*rule)(T , T)) : compare(rule) {} ;
protected:
    bool    (*compare) (T , T) ;//排序规则
};

template <typename T>
using bsTree = BinarySearchTree<T> ;

template<typename T>
bool BinarySearchTree<T>::remove(T data) {
    return false;
}

template<typename T>
BiTreeNode<T> *BinarySearchTree<T>::Digout(BiTreeNode<T> node) {
    return nullptr;
}

template<typename T>
BiTreeNode<T> *BinarySearchTree<T>::locate(T data) {
    return nullptr;
}

template<typename T>
bool BinarySearchTree<T>::insert(T data) {
    if (this->root == nullptr){
        this->root = new BiTreeNode<T>(data) ;
        return true ;
    }

    auto cur = this->root ;
    auto pre = cur ;

    while (cur != nullptr) {
        pre = cur ;

        if (this->compare(data , cur->data)){
            cur = cur->RChild ;
        }
        else{
            cur = cur->LChild;
        }
    }

    if (this->compare(data , pre->data)){
        pre->RChild = new BiTreeNode<T>(data);
    }else{
        pre->LChild = new BiTreeNode<T>(data);
    }

    return true ;
}


#endif //AVL_BINARYSEARCHTREE_H
