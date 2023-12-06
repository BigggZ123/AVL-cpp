//
// Created by lenovo on 2023/12/6.
//

#ifndef AVL_BITREE_H
#define AVL_BITREE_H

#include <queue>
#include <stack>

template <typename T>
class BiTreeNode{
public :
    BiTreeNode(){
        this->LChild = nullptr;
        this->RChild = nullptr;
    }
    explicit BiTreeNode(T data) : data (data) {
        this->LChild = nullptr;
        this->RChild = nullptr;
    };
    BiTreeNode<T>* LChild ;
    BiTreeNode<T>* RChild ;
    T data ;
};

template <typename T>
auto PreOrder (BiTreeNode<T> *node , bool (*visit) (BiTreeNode<T>*)) ->bool{
    if (node == nullptr){
        return true ;
    }

    if (not visit(node))
        return false ;
    if (not PreOrder(node->LChild , visit))
        return false ;
    if (not PreOrder(node->RChild , visit))
        return false ;
    return true ;
}

template <typename T>
auto InOrder (BiTreeNode<T> *node , bool (*visit) (BiTreeNode<T>*)) ->bool{
    if (node == nullptr){
        return true ;
    }

    if (not InOrder(node->LChild , visit))
        return false ;
    if (not visit(node))
        return false ;
    if (not InOrder(node->RChild , visit))
        return false ;
    return true ;
}

template <typename T>
auto PostOrder (BiTreeNode<T> *node , bool (*visit) (BiTreeNode<T>*)) ->bool{
    if (node == nullptr){
        return true ;
    }

    if (not PostOrder(node->LChild , visit))
        return false ;
    if (not PostOrder(node->RChild , visit))
        return false ;
    if (not visit(node))
        return false ;
    return true ;
}

template <typename T>
auto LevelOrder (BiTreeNode<T> *node , bool (*visit) (BiTreeNode<T>*)) ->bool{
    if (not node)
        return true ;

    std::queue<BiTreeNode<T>*> nodes ;
    nodes.push(node);
    while (not nodes.empty()){
        BiTreeNode<T>* cur = nodes.front();
        nodes.pop();

        if (not visit(cur))
            return false ;
        if (cur->LChild != nullptr)
            nodes.push(cur->LChild);
        if (cur->RChild != nullptr)
            nodes.push(cur->RChild);
    }
}

template <typename T>
auto Height (BiTreeNode<T> *node){
    if (not node){
        return -1 ;
    }

    int LH = Height(node->LChild);
    int RH = Height(node->RChild);

    if (LH > RH)
        return LH + 1 ;
    else
        return RH + 1 ;

}


template <typename T>
auto Balance_Factor(BiTreeNode<T>* node) -> int{
    return (Height(node->LChild) - Height(node->RChild) );
}

template <typename T>
class BiTree{
    public:
        BiTreeNode<T>* root ;
        BiTree() {
            this->root = nullptr;
        }
        explicit BiTree(BiTreeNode<T> node) : root(node) {};
        explicit BiTree(T data ) : root (new BiTreeNode<T>(data)) {} ;

        auto preOrder (bool (*visit) (BiTreeNode<T>*)){
            return PreOrder(this->root , visit);
        }
        auto postOrder (bool (*visit) (BiTreeNode<T>*)) {
            return PostOrder(this->root, visit);
        }
        auto inOrder (bool (*visit) (BiTreeNode<T>*)){
            return InOrder(this->root , visit);
        }
        auto height(){
            return Height(this->root);
        }
    };



#endif //AVL_BITREE_H
