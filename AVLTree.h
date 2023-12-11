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
    explicit AVLTree(bool(*rule)(T , T)) : BinarySearchTree<T>(rule) {};
    //据理解，构型检测不属于rotate的职责
    //这样才好将所谓的"左/右"旋有一个统一的理解
    //不妨这样记：所谓“左、右”，及当前节点在结果节点的左、右边
    static BiTreeNode<T>*       RRotate     (BiTreeNode<T>* node );
    static BiTreeNode<T>*       LRotate     (BiTreeNode<T>* node );
    static BiTreeNode<T>*       Rotate      (BiTreeNode<T>* node ) ;
    bool                        insert      (T data) override ;
    bool                        remove      (T data) override ;
protected:
    virtual BiTreeNode<T>*      insertHelper(BiTreeNode<T>* node , T data ) ;
    virtual BiTreeNode<T>*      removeHelper(BiTreeNode<T>* node , T data );
};



template<typename T>
BiTreeNode<T> *AVLTree<T>::Rotate(BiTreeNode<T> *node) {
    int _balanceFactor = Balance_Factor(node);
    //对不同构型的if-else
    if (_balanceFactor > max_balance_height){
        if (Balance_Factor(node->LChild) >= 0){
            return RRotate(node);
        }else{
            node->LChild = LRotate(node->LChild);
            return RRotate(node);
        }
    }
    else if (_balanceFactor < - max_balance_height){
        if (Balance_Factor(node->RChild) <= 0){
            return LRotate(node);
        }else{
            node->RChild = RRotate(node->RChild);
            return LRotate(node);
        }
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

template<typename T>
bool AVLTree<T>::insert(T data){
    this->root = this->insertHelper(this->root , data);
    return true ;
}

template<typename T>
BiTreeNode<T> *AVLTree<T>::insertHelper(BiTreeNode<T> *node, T data) {
    if (node == nullptr){
        return new BiTreeNode<T>(data);
    }
    if (this->compare(data , node->data)){
        node->RChild = this->insertHelper(node->RChild , data );
    }else{
        node->LChild = this->insertHelper(node->LChild , data );
    }
    node = this->Rotate(node);
    return node ;
}

template<typename T>
bool AVLTree<T>::remove(T data) {
    auto tmp =  this->removeHelper(this->root , data) ;
    if (tmp == nullptr){
        return false ;
    }
    else {
        this->root = tmp ;
        return true ;
    }
}

template<typename T>
BiTreeNode<T> *AVLTree<T>::removeHelper(BiTreeNode<T> *node, T data) {
    if (node == nullptr){
        return nullptr ;
    }

    if (node->data == data){
        if (node->RChild == nullptr and node->LChild == nullptr){
            delete node ;
            return nullptr;
        }
        else if (node->RChild == nullptr or node->LChild == nullptr){
            auto child = node->RChild ? node->RChild : node->LChild ;
            delete node ;
            node = child ;
        }
        else{
            //子节点数量为2
            auto tmp = node->LChild ;
            while (tmp->RChild != nullptr){
                tmp = tmp->RChild ;
            }
            T tmpData = tmp->data ;
            node->LChild = removeHelper(node->LChild , tmp->data);
            node->data = tmpData ;
        }

    }

    //因为compare此处不包含==的情况
    if (this->compare(data , node->data)){
        node->RChild = this->removeHelper(node->RChild , data);
    }else{
        node->LChild = this->removeHelper(node->LChild , data);
    }
    node = this->Rotate(node);
    return node ;
}
#endif //AVL_AVLTREE_H
