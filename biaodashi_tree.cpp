//
// Created by huangkaijie on 2017/10/12.
//用后缀表达式创建表达式树
//

#include "biaodashi_tree.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include "tree.h"
using namespace std;

BT * scanBiaoDaShi(string biaodashi)
{
    vector<BT*> stack;
    for(char c: biaodashi)
    {
        switch(c)
        {
            case '+':;
            case '-':;
            case '*':;
            case '/':
            {
                cout<<"这是操作符"<<endl;
                BT *right=stack.back();
                stack.pop_back();
                BT* left=stack.back();
                stack.pop_back();
                BT * node=new BT;
                node->key=c;
                node->left=left;
                node->right=right;
                stack.push_back(node);
                break;
            }
            default:
                cout<<"这是操作数"<<endl;
                BT * data=new BT;
                data->key=c;
                data->left=NULL;
                data->right=NULL;
                stack.push_back(data);
        }
    }
    return stack.back();

}

