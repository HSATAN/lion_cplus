//
// Created by huangkaijie on 2017/10/12.
//

#pragma once
#include "tree.h"
#include <iostream>
using namespace std;
typedef char DATATYPE;

typedef struct BTree
{
    struct BTree * left;
    struct BTree * right;
    DATATYPE key;
    int balance;
    int depth;
} BT;
BT * scanBiaoDaShi(string );
void print_tree(BT * );
void print_tree_first_format(BT*,int w);
int checkAdjustType(BT*);
class BinarySearchTree{
public:
    BT * root=NULL;
    void printTree() const ;

    bool isEmpty() const ;
    void insert(BT *,DATATYPE);
    void remove(DATATYPE);
    void adjust(BT *);


};
void heap_adjust(int[],int,int);//堆排序调整函数
void heap_sort(int [],int);
