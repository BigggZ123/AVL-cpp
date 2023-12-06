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
    if (not this->root){
        this->root = new BiTreeNode<T>(data) ;
    }
    auto cur = this->root ;
    auto pre = cur;
    while (cur != nullptr) {
//        cout << cur->data << endl;
        pre = cur ;
        if (this->compare(data , cur->data)){
//            cout << "Right" << endl ;
            cur = cur->RChild;
        }else{
//            cout << "Left" << endl ;
            cur =  cur->LChild;
//            if (not cur){
//                cout << "None in the Left" << endl ;
//            }
        }
    }

//    cout << "Fucking get out of the LOOP" << endl ;
//    cout << "PRE :\t " << pre->data << endl ;
    if (this->compare(data , pre->data))
        pre->RChild = new BiTreeNode<T>(data);
//        if (not pre->RChild)
//            cout << "Nothing in the Right of Pre-node" << endl ;
    else

        pre->LChild =  new BiTreeNode<T>(data);
//        if (not pre->LChild)
//            cout << "Nothing in the Left of Pre-node" << endl ;

//    cout << "FUCKING OK" << endl ;

    return true ;
}


#endif //AVL_BINARYSEARCHTREE_H
