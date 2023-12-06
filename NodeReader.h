//
// Created by lenovo on 2023/12/6.
//

#ifndef AVL_NODEREADER_H
#define AVL_NODEREADER_H

#include "BiTree.h"
#include <stack>

#include <iostream>
using namespace std ;
template <typename T>
void READ(BiTreeNode<T>* node){
    stack<BiTreeNode<T>*> nodes ;

    cout << node->data << endl << endl ;
    BiTreeNode<int>* cur = node ;
    nodes.push(node);
    char cmd = ' ';
    while (1){
        cout << "Input cmd : \t" ;
        cin >> cmd ;

        if (cmd == 'a'){
            if (cur->LChild != nullptr){
                cur = cur->LChild ;
                nodes.push(cur);
                cout << cur->data << endl ;
            }else{
                cout << "END!" << endl ;
            }
        }else if (cmd == 'd'){
            if (cur->RChild != nullptr){
                cur = cur->RChild ;
                nodes.push(cur);
                cout << cur->data << endl ;
            }else{
                cout << "END!" << endl ;
            }
        }
//        else if (cmd == 'p'){
//            if (cur->LChild){
//                cur = cur->LChild ;
//                nodes.push(cur->LChild);
//                cout << cur->data << endl ;
//            }else{
//                cout << "END!" << endl ;
//            }
//        }
        else if (cmd == 'w'){
            nodes.pop();
//            cout << "POPPPPPPP " << nodes.size()  << endl ;
            cur = nodes.top();
            cout << cur->data << endl ;
        }
//        else if (cmd == 'i') {
//            InOrder(cur, [](BiTreeNode<T> *node) -> bool {
//                cout << node->data << endl;
//                return true;
//            });
//        }
        else if (cmd == '#'){
            cout << "FINISHED" << endl ;
            break;
        }else {
            cout << "Invalid Command " << endl ;
        }
    }
}


#endif //AVL_NODEREADER_H
