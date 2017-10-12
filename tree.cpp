//
// Created by huangkaijie on 2017/9/23.
//
//
// Created by huangkaijie on 2017/10/12.
//用后缀表达式创建表达式树
//

#include <iostream>
#include <iomanip>
#include <vector>
#include "tree.h"
#include <cmath>
using namespace std;

BT * scanBiaoDaShi(string biaodashi)
{
    //用后缀表达式创建表达式树
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
void print_tree(BT * tree)
{
    //先序打印
    if(tree)
    {
        printf("%c\n",tree->key);
        if(tree->left)
        {
            print_tree(tree->left);
        }
        if(tree->right)
        {
            print_tree(tree->right);
        }
    }

}
void print_tree_middl(BT *tree)
{
    //中序打印
    if(tree)
    {
        print_tree_middl(tree->left);
        cout<<tree->key<<endl;
        print_tree_middl(tree->right);
    }

}
void print_tree_first_format(BT *tree,int w=0)
{
    //先序格式化打印树
    if(tree)
    {
        cout<<setw(w)<<(tree->key)<<endl;
        if(tree->left)
        {
            print_tree_first_format(tree->left,w+2);
        }
        if(tree->right)
        {
            print_tree_first_format(tree->right,w+2);
        }
    }
}

int get_depth(BT* tree)
{
    //返回树的高度
    if(!tree)
    {
        return 0;
    }
    int left=get_depth(tree->left)+1;
    int right=get_depth(tree->right)+1;
    return left>right ? left:right;
}
void BinarySearchTree::insert(BT *root,DATATYPE key) {
    if(root==NULL)
    {

        this->root=new BT;
        this->root->key=key;
        this->root->left=NULL;
        this->root->right=NULL;
        this->root->balance=0;
        root=this->root;
    }
    else if(key<root->key)//插入左子树
    {
        if(root->left==NULL)
        {
            BT *node = new BT;
            node->key = key;
            node->left=NULL;
            node->right=NULL;
            node->balance=0;
            root->left=node;
            root->balance += 1;
        }
        else
        {
            this->insert(root->left,key);
            //root->balance = get_depth(root->left) - get_depth(root->right);

        }

    }
    else if(key >= root->key)//插入右子树
    {
        if(root->right==NULL)
        {
            BT *node = new BT;
            node->key = key;
            node->left=NULL;
            node->right=NULL;
            node->balance=0;
            root->right=node;
            root->balance -= 1;
        }
        else
        {
            this->insert(root->right,key);
        }
    }
    root->balance = get_depth(root->left) - get_depth(root->right);

    if(abs(root->balance)==2)
    {
        cout<<"----"<<root->key<<"-----"<<endl;
        int type = checkAdjustType(root);
        cout<<type<<endl;
        if (type==1)
        {
            cout<<"type ll"<<endl;

        }
        else if(type==2)
        {
            cout<<"type rr"<<endl;

        }

    }
}

int get_depth_lr(BT *tree, int i)
{
    if(!tree)
    {
        return 0;
    }
    if(i==1)
    {
        int left=get_depth_lr(tree->left,i)+1;
        return left;
    }
    else
    {
        int left=get_depth_lr(tree->right,i)+1;
        return left;
    }

}

int checkAdjustType(BT *tree)
{
    int type1=get_depth_lr(tree,1);
    if (type1==3)
    {
        return 1;
    }
    int type2=get_depth_lr(tree,2);
    if (type2==3)
    {
        return 2;
    }
    return 0;
}
bool BinarySearchTree::isEmpty() const {
    if(this->root==NULL)
        return true;
    return false;
}
void BinarySearchTree::printTree() const {}
void BinarySearchTree::remove(DATATYPE) {}
void BinarySearchTree::adjust(BT *node) {}
