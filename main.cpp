#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "tree.h"
#include <iomanip>
#include "common.h"
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
//    string biaodashi="ab+cde+**";
//    BT * BDS=scanBiaoDaShi(biaodashi);
//    BinarySearchTree binarySearchTree;
//    cout<<"树是空："<<binarySearchTree.isEmpty()<<endl;
//    string string1="ecdbfgh";
//    for (char c:string1)
//    {
//        binarySearchTree.insert(binarySearchTree.root,c);
//    }
//    print_tree_first_format(binarySearchTree.root,0);
//    cout<<"树是空："<<binarySearchTree.isEmpty()<<endl;
//    test_map();
    int a[]={0,5,4,7,3,9,8,1,2,6};
//    for(int i=(sizeof(a)/ sizeof(int)-1)/2;i>0;i--)
//    {
//        heap_adjust(a,i,sizeof(a)/ sizeof(int)-1);
//    }
//    heap_sort(a,sizeof(a)/ sizeof(int)-1);
//
    int *p=new int[10];
    mergesort(a,0,9,p);
    for (int i=0;i<10;i++)
    {
        cout<<a[i]<<endl;
    }

    return 0;
}
