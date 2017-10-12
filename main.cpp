#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "tree.h"
#include "biaodashi_tree.h"
#include <iomanip>
using namespace std;

void signalHandler(int);
pthread_mutex_t mutex1;
int money;
struct thread_data{
    int thread_id;
    char * message;
};

BT * createTree(DATATYPE data, BT *tree)
{
    BT *node = new BT;


     //node = (BT*)malloc(sizeof(struct BTree));

    node->key=data;
    node->left= nullptr;
    node->right= nullptr;
    node->balance=0;
    tree=node;
    return tree;
}
BT * init(BT *tree,DATATYPE data)
{
    BT *node = new BT;


    //node = (BT*)malloc(sizeof(struct BTree));

    node->key=-1;
    node->left= nullptr;
    node->right= nullptr;
    node->balance=0;
    node->depth=1;
    tree=node;
    return tree;
}
int addNode(DATATYPE data, BT *tree)
{
    if (!tree)
    {return 0;}

    if (tree->key==-1 && tree->left== nullptr)
    {
        BT * node;
        node = new BT;
        node->key=data;
        node->right=nullptr;
        node->left=nullptr;
        node->balance=0;
        node->depth=1;
        tree->left=node;
        return 0;
    }
    if (tree->key==-1)
    {
        int balance = addNode(data,tree->left);
        return balance;
    }
     else if(tree->right== nullptr && tree->left==nullptr)
    {
        BT * node;
        node = new BT;
        node->key=data;
        node->right=nullptr;
        node->left=nullptr;
        node->balance=0;
        node->depth=1;
        tree->depth =2;
        if(tree->key>data)
        {


            tree->left=node;
            tree->balance += 1;

            return 1;
        } else{
            tree->right=node;
            tree->balance -= 1;
            return -1;
        }

    }
    else if(tree->right== nullptr)
    {
        if(tree->key<data)
        {
            BT * node;
            node = new BT;
            node->key=data;
            node->right= nullptr;
            node->left= nullptr;
            node->balance=0;
            node->depth=1;
            tree->right=node;
            tree->balance -= 1;
            return 0;
        } else{
          int balance =  addNode(data,tree->left);
            if (balance!=0)
            {
                tree->balance += 1;
                tree->depth += 1;
                return 1;
            }
            return 0;
        }
    }
    else if(tree->left==nullptr){
        if(tree->key>=data)
        {
            BT * node;
            node = new BT;
            node->key=data;
            node->right=nullptr;
            node->left=nullptr;
            node->balance=0;
            node->depth=1;
            tree->left=node;
            tree->balance += 1;


        } else
        {
           int balance = addNode(data,tree->right);
            if (balance!=0)
            {
                tree->balance += -1;
                tree->depth=1;
                return 0;
            }
        }
    } else{
        if(tree->key>data)
        {
           int balance = addNode(data,tree->left);
            if (balance!=0)
            {
                tree->balance += 1;
                tree->depth += 1;
                return 1;
            }

            return 0;
        } else
        {
          int balance =  addNode(data,tree->right);
            if (balance!=0)
            {
                tree->balance += -1;
                tree->depth += 1;
                return -1;
            }
            return 0;
        }
    }

}
vector<string> split(string name, string delim)
{
    vector<string> elems;
    int pos = 0;
    int end_index = 0;
    string temp;
    if (name.empty())
        return elems;
    while (pos >= 0)
    {
        pos = (int)name.find(" ", end_index);

        if (pos < 0)
        {

            break;

        }
        temp = name.substr(end_index, pos - end_index);
        end_index = pos + 1;
        elems.push_back(temp);
    }
    if (end_index != 0 && end_index < name.length())
    {
        elems.push_back(temp);
    }
    if (end_index==0)
    {
        elems.push_back(name);
    }
    return elems;
}
void create_tree_from_file(BT * tree)
{
    ifstream in("test.txt");
    string line;
    vector<string> name;
    while(getline(in,line))
    {
        name=split(line," ");
        while(!name.empty())
        {

           int balance =  addNode(stoi(name.back()),tree);
            tree->balance += balance;
            name.pop_back();
        }
    }
    in.close();
}

void print_tree(BT * tree)
{
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
    if(tree)
    {
        print_tree_middl(tree->left);
        cout<<tree->key<<endl;
        print_tree_middl(tree->right);
    }

}
void print_tree_first_format(BT *tree,int w=0)
{
    if(tree)
    {
        cout<<setw(w)<<tree->key<<endl;
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
BT * get_insert(BT * tree)
{
    if(!tree)
    {
        return tree;
    }
}
int get_depth(BT* tree)
{
    if(!tree)
    {
        return 0;
    }
    int left=get_depth(tree->left)+1;
    int right=get_depth(tree->right)+1;
    return left>right ? left:right;
}
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
    cout<<get_depth(BDS)<<endl;
    //print_tree_middl(BDS);
    print_tree_first_format(BDS);
    return 0;
}
