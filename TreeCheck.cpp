#include <iostream>
#include "ChatGPTTree.hpp"


int main(){
    Tree<int> tree;
    tree.addLeaf(15);
    tree.addLeaf(21);
    tree.addLeaf(30);
    tree.Traverse();
    tree.deleteLeaf(21);
    tree.Traverse();
    return 0;
}