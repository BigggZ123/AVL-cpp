//
// Created by lenovo on 2023/12/7.
//

#ifndef AVL_BINARYSEARCHTREE_H
#define AVL_BINARYSEARCHTREE_H
#include "NodeReader.h"
#include "BiTree.h"
#include <stack>

template <typename T>
class BinarySearchTree : public BiTree<T>{
public:
    bool                    insert      ( T data )  ;
    BiTreeNode<T>*          locate      ( T data );
    static BiTreeNode<T>*   Digout      ( BiTreeNode<T>* node);
    bool                    remove      (T data) ;
    explicit BinarySearchTree (bool(*rule)(T , T)) : compare(rule) {} ;
protected:
    bool    (*compare) (T , T) ;//排序规则
};

template <typename T>
using bsTree = BinarySearchTree<T> ;


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

template<typename T>
BiTreeNode<T> *BinarySearchTree<T>::Digout(BiTreeNode<T>* node) {
    if (node == nullptr){
        return nullptr;
    }
    if (node->RChild == nullptr and node->LChild == nullptr){
        return nullptr;
    }
    if (node->LChild == nullptr){
        return node->RChild ;
    }
    if (node->RChild == nullptr){
        return node->LChild;
    }

    //度为2
    auto cur = node->LChild ;
    if (cur->RChild == nullptr){
        cur->RChild = node->RChild ;
        return cur ;//特殊情况
    }

    auto pre = cur ;
    auto RChild = node->RChild ;
    auto LChild = node->LChild ;

    while (cur != nullptr){
        if (cur->RChild != nullptr){
            pre = cur ;
        }
        cur =  cur->RChild ;
    }
    auto newNode =  pre->RChild ;
    pre->RChild = nullptr ;
    newNode->RChild = RChild ;
    newNode->LChild = LChild ;
    return newNode ;
}

template<typename T>
BiTreeNode<T> *BinarySearchTree<T>::locate(T data) {
    auto cur = this->root ;
    while (cur != nullptr){
        if (cur->data == data) {
            break ;
        }
        if (this->compare(data , cur->data)){
            cur = cur->RChild ;
        }
        else{
            cur = cur->LChild ;
        }
    }
    return cur ;
}

template <typename T>
bool BinarySearchTree<T>::remove(T data) {
    if (this->root->data == data ){
        this->root = this->Digout(this->root);
        return true;
    }
    auto cur =  this->root ;
    std::stack<BiTreeNode<T>*> path ;

    while (true){
        if (cur == nullptr){
            return false ;
        }
        if (cur->data == data){
            break ;
        }
        if (this->compare(data , cur->data)){
            path.push(cur);
            cur = cur->RChild ;
        }else{
            path.push(cur);
            cur =  cur->LChild;
        }
    }
    auto pre = path.top();
    if (this->compare(data , pre->data)){
        pre->RChild =  this->Digout(pre->RChild);
    }else{
        pre->LChild =  this->Digout(pre->LChild);
    }
    return true ;
}

#endif //AVL_BINARYSEARCHTREE_H
