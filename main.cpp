#include <iostream>
#include "BiTree.h"
#include <vector>
#include "NodeReader.h"
using namespace std ;

int main() {
//    std::cout << "Hello, World!" << std::endl;
    vector<BiTreeNode<int>*> nodes ;
    nodes.reserve(10);
    for (int i = 0 ; i < 10 ; i ++){
        nodes.push_back(new BiTreeNode<int>(i));
    }

    nodes[0]->LChild = nodes[1];
    nodes[0]->RChild = nodes[2];
    nodes[1]->LChild = nodes[3];
    nodes[1]->RChild = nodes[4];
    nodes[3]->LChild = nodes[5];
    nodes[5]->LChild = nodes[6];

//    LevelOrder<int>(nodes[0] , [](BiTreeNode<int>* node) -> bool {
//        cout << node->data << endl ;
//        return true ;
//    });
//    for (int i = 0 ; i < 5 ; i ++){
//        cout << i << "\t" << Height(nodes[i]) << endl ;
//    }

//    cout << Balance_Factor(nodes[0]) << endl ;
//    cout << Height(nodes[0]->LChild) << endl ;
//    cout << Height(nodes[0]->LChild) - Height(nodes[0]->RChild) << endl ;

    READ(nodes[0]);

    return 0;
}
