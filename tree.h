//
// Created by huangkaijie on 2017/10/12.
//

#pragma once
typedef char DATATYPE;

typedef struct BTree
{
    struct BTree * left;
    struct BTree * right;
    DATATYPE key;
    int balance;
    int depth;
} BT;
