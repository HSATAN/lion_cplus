#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "tree.h"
#include <iomanip>
using namespace std;




int main() {
    BT *tree;
//    tree = init(tree,-1);
//    create_tree_from_file(tree);
//    printf("%d\n",get_depth(tree->left));
//    print_tree(tree->left);
//    string a;
//    cout<<typeid(a).name()<<endl;
//    auto i="huangkaijie";
//    cout<<i<<endl;
//    cout<<typeid(i).name()<<endl;
    string biaodashi="ab+cde+**";
    BT * BDS=scanBiaoDaShi(biaodashi);
    BinarySearchTree binarySearchTree;
    cout<<"树是空："<<binarySearchTree.isEmpty()<<endl;
    string string1="ecdbfg";
    for (char c:string1)
    {
        binarySearchTree.insert(binarySearchTree.root,c);
    }
    print_tree_first_format(binarySearchTree.root,0);
    cout<<"树是空："<<binarySearchTree.isEmpty()<<endl;
    return 0;
}
